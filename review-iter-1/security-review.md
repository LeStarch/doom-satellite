# security-review — iteration 1 (LOCAL ONLY, not posted)
Diff: main...6086a30

Untrusted input: UDP datagrams from the coprocessor link reach `GenericHub` -> `BufferRepeater` -> `FrameBufferAdapter.packedIn`.

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| — | — | FrameBufferAdapter.cpp packedIn/unpackFrame/unpackPalette | Traced: null, short, bad-kind, header-short, geometry (0 / > 80x50) and exact-size checks precede every read; deserializers are bounded by `setBuffLen`. Pixels view never exceeds received size. No finding. | — |
| — | — | ComCcsdsSubtopologyConfig.cpp ArenaAllocator | Bounds check on padding and size is overflow-safe (subtractions guarded). No finding. | — |

Findings: 0 must fix, 0 suggestion, 0 could fix, 0 future work. Verdict: Go.
