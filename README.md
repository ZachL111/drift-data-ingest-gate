# drift-data-ingest-gate

`drift-data-ingest-gate` is a focused C++ codebase around build a C++ toolkit that studies ingest behavior through round-trip fixtures, with lossless normalization checks and no credentials or hosted services. It is meant to be easy to inspect, run, and extend without a hosted service.

## Drift Data Ingest Gate Walkthrough

I would read the project from the outside in: command, fixture, model, then roadmap. That keeps the data engineering idea grounded in files that can be checked locally.

## Reason For The Project

This is not a wrapper around a service. It is a self-contained project that shows how the model behaves when demand, capacity, latency, risk, and weight move in different directions.

## Where Things Live

- `src`: primary implementation
- `tests`: verification harness
- `fixtures`: compact golden scenarios
- `examples`: expanded scenario set
- `metadata`: project constants and verification metadata
- `docs`: operations and extension notes
- `scripts`: local verification and audit commands

## Capabilities

- Includes extended examples for pipeline state, including `surge` and `degraded`.
- Documents quality gates tradeoffs in `docs/operations.md`.
- Runs locally with a single verification command and no external credentials.
- Stores project constants and verification metadata in `metadata/project.json`.
- Adds a repository audit script that checks structure before running the language verifier.

## How It Is Put Together

The design is intentionally direct: parse or construct a signal, score it, classify it, and verify the expected branch. This makes the repository useful for studying data engineering behavior without needing a service or database unless the language project itself is SQL. The C++ project uses a small library boundary and a compiled assertion harness.

## Getting It Running

Use a normal shell with C++ available on `PATH`. The verifier is written as a PowerShell script because the portfolio was assembled on Windows.

## Data Notes

`boundary` is the first example I would inspect because it lands on the `review` path with a score of 151. The broader file also keeps `degraded` at -27 and `surge` at 250, which gives the model a useful low-to-high spread.

## Command Examples

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

This runs the language-level build or test path against the compact fixture set.

## Check The Work

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/audit.ps1
```

The audit command checks repository structure and README constraints before it delegates to the verifier.

## Possible Extensions

- Add malformed input fixtures so the failure path is as visible as the happy path.
- Split the scoring constants into a typed configuration object and validate it before use.
- Add a comparison mode that shows how decisions change when one signal is adjusted.
- Add one more data engineering fixture that focuses on a malformed or borderline input.

## Tradeoffs

This code is local-first. It makes no claim about deployed usage and avoids credentials, hosted state, and environment-specific setup.
