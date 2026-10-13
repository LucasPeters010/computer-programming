# Atomic Score Import

**Level: Hard**

Make an import all-or-nothing: one invalid line must leave an existing collection untouched.

## Requirements

- ScoreStore keeps unique positive student IDs and scores 0..100. importScores reads zero or more physical lines, each containing exactly two integers: ID SCORE.
- Validate lines in input order. On each line, grammar errors have first priority, then invalid ID, invalid score, then duplicate ID. Duplicates include IDs already stored and IDs earlier in this import.
- Throw ImportError carrying the physical line number and one of: "Malformed record", "Invalid ID", "Invalid score", "Duplicate ID". Blank lines are malformed.
- If any line fails, preserve the complete pre-import store. If all lines succeed, append the records. Empty input is a successful no-op.
- size() gives number of stored records; scoreFor(id) throws std::out_of_range("Unknown ID") if missing. report() lists ascending ID order as ID SCORE, each followed by newline.
- Implement ImportError as a small class with line() and message(); no exception inheritance is required.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use vectors and custom exception objects; no maps, files on disk or global state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Duplicate within one import; first/last line invalid; whitespace-only line; invalid import after a valid one.

<details>
<summary>One hint (open only if needed)</summary>

Consider where new records can live before you know that the entire import is valid.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
