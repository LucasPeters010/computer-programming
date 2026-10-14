# Reverse Valid Numbers

**Level: Medium**

Combine a vector-backed stack with a small stream task.

## Requirements

- reverseNumbers reads whitespace-separated integers until EOF. If extraction fails on non-whitespace input, throw std::runtime_error("Invalid number").
- Return the numbers in reverse order as a string separated by single spaces, without leading/trailing space or newline. Empty input returns empty string.
- Use a vector as a stack and remove its last element while building the result. No separate class, linked nodes or custom exception.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: streams + vector stack + exceptions. No std::reverse.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: One value; trailing whitespace; invalid middle token; no numbers.

<details>
<summary>One hint (open only if needed)</summary>

A failed read after consuming only trailing whitespace is different from a bad token.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
