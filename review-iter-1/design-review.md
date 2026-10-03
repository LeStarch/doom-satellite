# design-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| DES-1 | — | DoomFlight topology HubFrames | Ownership traced for each path: hub original -> repeater.deallocate -> hub.bufferOutReturn; ECHO copy -> frameAdapter.echoIn -> hub.bufferIn -> bufferInReturn -> echoOutReturn -> echoReturn -> hubBufferManager; LOCAL copy -> packedIn -> packedInReturn -> hubBufferManager. Each buffer returned exactly once. No finding. | — |
| DES-2 | future work | Svc/GenericHub send_data (upstream) | `send_data` asserts if `allocate_out` returns an empty buffer; with 12 large bins on DoomFlight a stalled UDP path could exhaust the pool and assert rather than drop. Preexisting upstream behavior; repeater is configured WARNING_ON_OUT_OF_MEMORY so repeater allocation failures already degrade gracefully. Not observed in hardware runs. | Acknowledged; candidate upstream issue. |
| DES-3 | — | FrameBufferAdapter echo relay | Echo relay lives in the adapter because GenericHub returns bufferIn buffers on the matching bufferInReturn index and the repeater has no return input. Documented in topology comment and SDD §3.3. Acceptable. | — |
