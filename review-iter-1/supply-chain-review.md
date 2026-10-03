# supply-chain-review — iteration 1 (LOCAL ONLY, not posted)

| # | Tag | Location | Finding | Disposition |
|---|---|---|---|---|
| SC-1 | could fix | .gitmodules lib/fprime-zephyr | Submodule now pins 51b623c (JPL-Devin/fprime-zephyr `devin/1790995930-touch-reset-generalize`, PR fprime-community/fprime-zephyr#66 head) but `branch =` still names the superseded `devin/1790989263-zephyr-touch-reset`; `git submodule update --remote` would move to the wrong code. | Fixed: branch updated. |
| SC-2 | future work | lib/fprime-zephyr | Pin is an unmerged fork branch; once PR #66 merges, repin to an upstream commit. | Acknowledged. |

No new third-party packages; pinned SHAs only. Verdict: Go.
