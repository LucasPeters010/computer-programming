# Strict Measurement Reader

**Level: Easy**

Read exactly three numbers from a stream, distinguishing malformed input from an invalid measurement.

## Requirements

- readMeasurements reads length, width and height as doubles from a supplied istream, allowing whitespace around tokens.
- Missing values, nonnumeric tokens, non-finite values or any fourth non-whitespace token throw std::runtime_error("Malformed measurement input").
- After syntactic validation succeeds, any dimension <= 0 throws std::invalid_argument("Dimensions must be positive"). Syntax errors take priority.
- Return a vector of the three numbers. volume(input) calls the reader and returns their product.
- Do not print from these functions or catch an exception merely to suppress it. The caller handles errors. You may assume a valid volume fits in double.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Whitespace-only input; missing third value; fourth token; a negative number with extra input.

<details>
<summary>One hint (open only if needed)</summary>

A successful read of three values does not establish that the entire input is valid.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
