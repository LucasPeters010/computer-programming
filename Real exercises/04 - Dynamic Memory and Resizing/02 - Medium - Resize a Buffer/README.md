# Resize a Buffer

**Level: Medium**

Preserve values when replacing a dynamic allocation.

## Requirements

- Buffer(n) receives n >= 0 and starts with n zeroes. size() reports length and at(index) checks it, throwing std::out_of_range("Invalid index") when invalid.
- resize(n) preserves the first min(oldSize,n) values and zero-initializes growth. Negative n throws std::invalid_argument("Negative size") without changes.
- You may allocate a new array on every resize; there is no separate capacity. Destructor releases memory. Copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Raw dynamic array only. No capacity, reserve or copy constructor required.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Resize to zero; grow from zero; unchanged size; invalid resize preserves data.

<details>
<summary>One hint (open only if needed)</summary>

Determine how many old values fit in the new array before copying.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
