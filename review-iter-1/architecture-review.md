# architecture-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| ARC-1 | — | DoomFlight instances.fpp frameTlmProcessor | Instantiated outside DoomSubtopology with the subtopology's base id + 0x3000 so channel ids match; DoomCoprocessor no longer instantiates it, so ids do not collide in the merged dictionary (merge_packets --check passes). No finding. | — |
| ARC-2 | — | Removal of TlmSplitter/TlmEchoReceiver | No remaining references (rg). hub.tlmOut wired directly to CdhCore.tlmSend. No finding. | — |
| ARC-3 | future work | DoomFlight memory | OCRAM arena at 240/256 KB (93.75%); little margin for added ComCcsds/hub allocations. | Acknowledged; PSRAM boards on order. |
