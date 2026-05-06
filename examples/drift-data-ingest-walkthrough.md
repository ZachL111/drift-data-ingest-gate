# Drift Data Ingest Gate Walkthrough

This walk-through keeps the domain vocabulary close to the data instead of burying it in prose.

| Case | Focus | Score | Lane |
| --- | --- | ---: | --- |
| baseline | schema drift | 107 | watch |
| stress | lineage depth | 224 | ship |
| edge | partition skew | 203 | ship |
| recovery | quality gap | 184 | ship |
| stale | schema drift | 252 | ship |

Start with `stale` and `baseline`. They create the widest contrast in this repository's fixture set, which makes them better review anchors than the middle cases.

`stale` is the optimistic case; use it to make sure the scoring path still rewards strong signal.
