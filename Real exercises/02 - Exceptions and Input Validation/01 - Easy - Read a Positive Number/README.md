# Read a Positive Number

**Level: Easy**

Validate one stream extraction and report two kinds of error.

## Requirements

- readPositive(input) reads one double and returns it.
- Failed extraction throws std::runtime_error("Not a number"). A successfully read value <= 0 throws std::invalid_argument("Must be positive"). Assume all successfully read values are finite.
- Read only ONE value; trailing input belongs to the caller and must not be checked or consumed deliberately.
- Do not print or catch errors inside this function. The caller handles them.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty input; negative value; valid decimal; valid value followed by another token.

<details>
<summary>One hint (open only if needed)</summary>

Stream extraction can be used as a condition to check whether reading succeeded.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
