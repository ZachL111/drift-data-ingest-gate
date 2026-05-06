# drift-data-ingest-gate

`drift-data-ingest-gate` keeps a focused C++ implementation around data engineering. The project goal is to build a C++ toolkit that studies ingest behavior through round-trip fixtures, with lossless normalization checks and no credentials or hosted services.

## Why I Keep It Small

This is intentionally local and self-contained so it can be inspected without credentials, services, or seeded history.

## Drift Data Ingest Gate Review Notes

`stale` and `baseline` are the cases worth reading first. They show the optimistic and cautious ends of the fixture.

## Included Behavior

- `fixtures/domain_review.csv` adds cases for schema drift and lineage depth.
- `metadata/domain-review.json` records the same cases in structured form.
- `config/review-profile.json` captures the read order and the two review questions.
- `examples/drift-data-ingest-walkthrough.md` walks through the case spread.
- The C++ code includes a review path for `schema drift` and `schema drift`.
- `docs/field-notes.md` explains the strongest and weakest cases.

## Internal Model

The repository has two validation layers: the original compact policy fixture and the domain review fixture. They are separate so one can change without hiding failures in the other.

The C++ implementation avoids hidden state so fixture changes are easy to reason about.

## Try It Locally

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

## Validation

The same command runs the local verification path. The highest-scoring domain case is `stale` at 252, which lands in `ship`. The most cautious case is `baseline` at 107, which lands in `watch`.

## Scope

No external service is required. A deeper version would add more negative cases and a clearer boundary around invalid input.
