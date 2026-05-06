# Review Journal

The repository goal stays the same: build a C++ toolkit that studies ingest behavior through round-trip fixtures, with lossless normalization checks and no credentials or hosted services. This note explains the added review angle.

The local checks classify each case as `ship`, `watch`, or `hold`. That gives the project a small review vocabulary that matches its data engineering focus without claiming live deployment or external usage.

## Cases

- `baseline`: `schema drift`, score 107, lane `watch`
- `stress`: `lineage depth`, score 224, lane `ship`
- `edge`: `partition skew`, score 203, lane `ship`
- `recovery`: `quality gap`, score 184, lane `ship`
- `stale`: `schema drift`, score 252, lane `ship`

## Note

The useful failure mode here is a wrong decision on a named case, not a vague style disagreement.
