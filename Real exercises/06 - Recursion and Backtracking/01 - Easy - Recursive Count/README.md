# Recursive Count

**Level: Easy**

Write one recursive traversal with a clear stopping condition.

## Requirements

- countFrom(values,target,index) counts occurrences of target from index to the end of values. Precondition: 0 <= index <= values.size().
- Return zero at index==size. Otherwise process the current element and use a recursive call for the remaining suffix.
- Do not modify or copy the input. No loops or standard counting algorithms. Assume at most 500 values.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty input; no matches; all matches; starting at the end.

<details>
<summary>One hint (open only if needed)</summary>

Describe the answer as the current element contribution plus the answer for the rest.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
