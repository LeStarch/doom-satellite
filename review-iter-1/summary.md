# Local review summary — iteration 1 (LOCAL REVIEW ONLY — NOT POSTED TO GITHUB)

Scope: whole doom-satellite repo diff `main...6086a30` (frame path rework, generalized touch reset, OCRAM allocator, ENET checksum fix).
Reviewers run inline against the local diff: security, supply-chain, fprime-code, stale-documentation, design, architecture, test-quality.

| Tag | Count | IDs |
|---|---|---|
| must fix | 4 | CPP-1 (cross-thread counter race), DOC-1 (wrong packed-frame size comments), TQ-1 (echo ports untested), TQ-2 (UT link failure) |
| could fix | 3 | SC-1 (.gitmodules branch), CPP-2 (ignored configure status), DOC-2 (SDD port kinds/concurrency) |
| future work | 6 | SC-2, DOC-3, DOC-4, DES-2, ARC-3, TQ-4 |

All must-fix and could-fix items fixed in 6086a30 (TQ-1/TQ-2) and 8b7f374. Verdict after fixes: Go.

## Tests this iteration
- FrameBufferAdapter UTs: 11/11 pass. fprime-stress `fprime-util check --recursive`: 3/3 pass; node/py_compile checks pass.
- Builds: Teensy 4.1 DoomFlight, aarch64 DoomCoprocessor, `merge_packets.py --check` (58 packets, 98 channels).
- Hardware (Pi <-> GenericHub/Ethernet <-> Teensy, DOOM running, GDS on CDC ACM): hub_test.py + frame_test.py 10 passed, 1 skipped; flashed by 134-baud touch (no button).
- Not green: root-wide native `fprime-util build --ut` fails compiling lib/fprime-zephyr Os sources (`zephyr/kernel.h` not found) — the native UT build pulls in Zephyr-only modules; preexisting build-configuration issue, not from this diff.
