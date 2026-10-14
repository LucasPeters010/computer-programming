# Can a Subset Reach the Target

**Level: Medium**

Practise two recursive branches without constructing or ranking solutions.

## Requirements

- canMake(values,target,index) reports whether a subset of values from index onward sums to target. Each index may be used at most once.
- Values are positive integers, target >= 0, and 0 <= index <= size. The empty selection makes target zero.
- Explore including or excluding the current value recursively. Return only bool; no result vectors, all-solutions list, tie rules or minimum coin counts.
- Assume at most 20 values; no dynamic programming is required.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use recursive choice branching. No loops that enumerate bit masks or global state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Target zero; no values; one exact match; target smaller than all values.

<details>
<summary>One hint (open only if needed)</summary>

The two branches differ in whether the current value is included in the remaining target.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
