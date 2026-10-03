# stale-documentation-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| DOC-1 | must fix | DoomFlightTopology.cpp, DoomCoprocessorTopology.cpp `HUB_LARGE_BUFFER_SIZE` comment | Says packed frames are 4,008 bytes / 4,024 with the hub header; the kind byte is a U8, so the frame is 9 + 4,000 = 4,009 bytes and 4,025 with the 16-byte hub header (SDD §3.2 is correct). | Fixed. |
| DOC-2 | could fix | FrameBufferAdapter docs/sdd.md | Port kinds and concurrency not documented after making entry ports guarded; unconnected-`packedOut` drop behavior undocumented. | Fixed: §3.1 port kinds, new §3.4. |
| DOC-3 | future work | DoomSatellite/DoomFlight/README.md | Generic auto-generated README (mentions FileHandling/DataProducts subtopologies, no hub/frame path). Preexisting. | Acknowledged. |
| DOC-4 | future work | prj.conf "DIAGNOSTIC (temporary)" logging block | Preexisting temporary bring-up logging. | Acknowledged. |
