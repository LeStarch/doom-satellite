# fprime-code-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| CPP-1 | must fix | FrameBufferAdapter.fpp frameIn/paletteIn/packedIn | On DoomCoprocessor `frameIn` runs on the DOOM rate-group thread and `packedIn` (echo) on the hub UDP receive thread; both call `rejectFrame`/`rejectPalette`, which increment `m_framesRejected`/`m_palettesRejected` unsynchronized (data race). | Fixed: the three entry ports are `guarded`; return ports stay `sync` (called within the guarded call, same thread). SDD §3.4 documents it. |
| CPP-2 | could fix | DoomFlightTopology.cpp configureTopology | `(void)touchReset.configure(...)` discards an `Fw::Success` error return (unhandled error return). | Fixed: prints "Touch reset unavailable" on failure, matching the component SDD example. |
| CPP-3 | — | FrameBufferAdapter.cpp packedOutReturn_handler | `FW_ASSERT` on a foreign/unlent return buffer is an internal ownership invariant (GenericHub returns the same buffer synchronously); not ground-reachable. No finding. | — |
| CPP-4 | — | FrameBufferAdapter.hpp storage | Fixed member storage, no allocation, C++14, F Prime types. No finding. | — |

Verdict after fixes: Go.
