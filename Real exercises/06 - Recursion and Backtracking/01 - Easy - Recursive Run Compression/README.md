# Recursive Run Compression

**Level: Easy**

Use recursion to summarize consecutive equal values and to find the longest run.

## Requirements

- compressRuns returns a vector of strings VALUE:COUNT for each maximal run, in original order. Example {4,4,-1,-1,-1,4} produces {"4:2","-1:3","4:1"}.
- longestRun returns the length of the longest consecutive equal run, or zero for empty input.
- Both functions must perform the traversal recursively. You may add helpers with parameters such as an index or current run state.
- Do not mutate the input. Work in O(n) time, excluding string formatting; do not repeatedly copy vector suffixes.
- Assume at most 500 input values, so recursion depth is manageable.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No loops in your traversal helpers, std::algorithm traversal, or global state. Loops in the supplied tester are unrelated.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty input; one value; final run longest; negative values; all values equal.

<details>
<summary>One hint (open only if needed)</summary>

Decide what must happen when the next value changes and when the input ends.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
