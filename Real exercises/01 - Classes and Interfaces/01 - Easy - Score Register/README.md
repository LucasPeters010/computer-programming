# Score Register

**Level: Easy**

Practice one class that stores and summarizes scores.

## Requirements

- ScoreRegister starts with no scores. add(score) accepts integers 0..100 and returns true. Invalid scores return false without being stored.
- average() returns a double average, or 0 for an empty register. countAtLeast(limit) counts scores >= limit; any integer limit is allowed.
- Only one class is needed. No input parsing, sorting, strings or exceptions.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use the supplied vector field. No additional classes.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: No scores; scores 0 and 100; rejected score does not affect average.

<details>
<summary>One hint (open only if needed)</summary>

Use the number of stored scores when calculating the average; avoid integer division.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
