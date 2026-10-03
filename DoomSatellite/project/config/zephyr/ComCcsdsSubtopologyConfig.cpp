// ======================================================================
// \title  ComCcsdsSubtopologyConfig.cpp
// \brief  Zephyr override: ComCcsds (and DoomFlight hub) setup allocations come from a fixed arena in FlexRAM OCRAM
// ======================================================================
#include "ComCcsdsSubtopologyConfig.hpp"

#include <Fw/Types/Assert.hpp>
#include <zephyr/devicetree.h>
#include <zephyr/linker/section_tags.h>

namespace {

//! Hands out one-shot, never-freed allocations from a fixed arena. Used during single-threaded topology setup only.
class ArenaAllocator final : public Fw::MemAllocator {
  public:
    ArenaAllocator(U8* const arena, const FwSizeType size) : m_arena(arena), m_size(size), m_used(0) {}

    void* allocate(const FwEnumStoreType identifier,
                   FwSizeType& size,
                   bool& recoverable,
                   FwSizeType alignment) override {
        (void)identifier;
        recoverable = false;
        FW_ASSERT(alignment > 0);
        const FwSizeType misalignment =
            reinterpret_cast<PlatformPointerCastType>(this->m_arena + this->m_used) % alignment;
        const FwSizeType padding = (misalignment == 0) ? 0 : (alignment - misalignment);
        if ((padding > (this->m_size - this->m_used)) || (size > (this->m_size - this->m_used - padding))) {
            size = 0;
            return nullptr;
        }
        const FwSizeType offset = this->m_used + padding;
        this->m_used = offset + size;
        return this->m_arena + offset;
    }

    void deallocate(const FwEnumStoreType identifier, void* ptr) override {
        (void)identifier;
        (void)ptr;
    }

  private:
    U8* const m_arena;
    const FwSizeType m_size;
    FwSizeType m_used;
};

// The 512 KB OCRAM2 holds the Zephyr image and the malloc heap. The 256 KB FlexRAM OCRAM is otherwise unused.
constexpr FwSizeType SETUP_ARENA_SIZE = 240 * 1024;
#if DT_NODE_EXISTS(DT_NODELABEL(ocram))
Z_GENERIC_SECTION(OCRAM) __aligned(8) U8 setupArena[SETUP_ARENA_SIZE];
#else
__aligned(8) U8 setupArena[SETUP_ARENA_SIZE];
#endif
ArenaAllocator setupAllocator(setupArena, SETUP_ARENA_SIZE);

}  // namespace

namespace ComCcsds {
namespace Allocation {
Fw::MemAllocator& memAllocator = setupAllocator;
}  // namespace Allocation
}  // namespace ComCcsds
