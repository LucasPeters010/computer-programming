# Recursive Buffer Total

**Level: Medium**

Combine simple array ownership with a recursive query.

## Requirements

- NumberArray(n) receives n >= 0 and owns n zero-initialized integers. at(index) returns a writable reference or throws std::out_of_range("Invalid index").
- total() sums the array recursively through a private helper. Assume the sum fits int.
- Constructor and destructor manage storage. Copying disabled. No resize, parsing or capacity management.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: dynamic memory + recursion. No loop in the summation helper.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Empty array; negative values; out-of-range access.

<details>
<summary>One hint (open only if needed)</summary>

The helper can receive the next array index to process.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
