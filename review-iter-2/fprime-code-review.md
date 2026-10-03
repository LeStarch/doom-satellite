# fprime-code-review — iteration 2 (LOCAL ONLY, not posted) — scope: main...HEAD after iteration-1 fixes (8b7f374 + clang-format)

| # | Tag | Finding | Disposition |
|---|---|---|---|
| CPP-1 | resolved | Guarded entry ports; re-entry check: frameIn -> packedOut -> hub.bufferIn -> bufferInReturn -> packedOutReturn (sync, no lock) — no self-deadlock. DoomFlight packedIn -> frameOut -> frameTlmProcessor does not re-enter the adapter. | — |
| CPP-2 | resolved | touchReset.configure status handled. | — |
| CPP-5 | could fix | FrameBufferAdapter.hpp and ComCcsdsSubtopologyConfig.cpp did not match .clang-format. | Fixed (clang-format -i). |
