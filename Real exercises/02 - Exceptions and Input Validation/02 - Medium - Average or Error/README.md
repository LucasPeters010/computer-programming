# Average or Error

**Level: Medium**

Use a small custom exception carrying information about bad data.

## Requirements

- InvalidScore(index) stores the zero-based position of a bad score; position() returns it. This is an ordinary class, not an exception subclass.
- checkedAverage(scores) throws std::runtime_error("No scores") for empty input.
- Otherwise check scores in order. A value outside 0..100 throws InvalidScore carrying its index. Valid input returns a double average.
- Do not modify the vector. No parsing or output formatting.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: First/last invalid score; several invalid scores; valid boundary values.

<details>
<summary>One hint (open only if needed)</summary>

You can throw and catch an object of your own class; inheritance is not required here.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
