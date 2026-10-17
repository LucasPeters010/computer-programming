# Second Distinct Minimum

**Level: Hard**

Combine an algorithm with two custom failure types.

## Requirements

- secondMinimum returns the second-smallest distinct integer without changing the vector.
- Fewer than two input values: throw TooFewValues carrying the number supplied. Otherwise, if all values are equal: throw AllEqual carrying that value.
- Implement count() and value() in the respective small classes. Neither needs exception inheritance.
- All int values are permitted. Sorting a COPY is allowed; there is no one-pass or constant-memory requirement.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Automatically tested in main.cpp: Empty vector; repeated minimum; all equal; negative and extreme int values.
Also covered: boundary and extreme values, exact exception payloads/messages, and relevant input-preservation or parser-recovery cases. No manual additions are needed to run these checks.

<details>
<summary>One hint (open only if needed)</summary>

Repeated occurrences of the minimum do not count as the second distinct value.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the automatic checks; optional extra cases are welcome. Do not commit executables.
