# test-quality-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| TQ-1 | must fix | FrameBufferAdapter UTs | Echo relay ports (echoIn/echoOut/echoOutReturn/echoReturn, incl. unconnected echoOut) had no unit test. | Fixed: Echo.RelaysAndReturns, Echo.ReturnsWhenUnconnected. |
| TQ-2 | must fix | FrameBufferAdapterTester.hpp | ODR-used `static constexpr` members (WIDTH/HEIGHT/PIXELS) lacked out-of-line definitions under C++14 -> UT link failure. | Fixed. |
| TQ-3 | — | test/int/frame_test.py | Verifies pack on coprocessor, unpack on flight, echo unpack on coprocessor, palettes both ends, rows 000/049 and palette downlinked, and no rejection counter > 0. Run on hardware. No finding. | — |
| TQ-4 | future work | hub_test.py test_remote_telemetry | Skipped: coprocessor cmdDisp telemetry deliberately not packetized; coverage moved to frame_test.py. | Acknowledged. |
