# Line Score Summary

**Level: Easy**

Parse named score lines and produce a precisely formatted summary through supplied streams.

## Requirements

- Each physical input line has NAME followed by one or more integer scores in 0..100. NAME is one nonempty whitespace-delimited token. Input may contain leading/trailing whitespace.
- A line is invalid if it has no scores, an out-of-range score, or any malformed score token. Skip it and increment the returned rejected-line count. Blank lines are invalid.
- For each valid line print NAME: count=N average=A, with average fixed to two decimals and a newline.
- summarizeScores must read and write through its parameters. Do not print partial output for a rejected line. Assume line totals fit int.
- Formatting changes to the supplied output stream are allowed.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use getline and string streams; do not use regex.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: A name without scores; trailing garbage; trailing whitespace; score 0 or 100.

<details>
<summary>One hint (open only if needed)</summary>

A line-level stream lets one bad record end without consuming the next record.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
