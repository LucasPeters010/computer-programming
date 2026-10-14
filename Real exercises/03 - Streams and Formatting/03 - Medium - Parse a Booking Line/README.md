# Parse a Booking Line

**Level: Medium**

Validate one record and write results through reference parameters.

## Requirements

- parseBooking(line,name,start,end) accepts exactly NAME START END, with a single-token name and integer hours satisfying 0 <= START < END <= 24.
- Return true and set all three output parameters when valid. Return false on malformed input, extra tokens or invalid hours.
- On failure ALL output parameters must keep their original values.
- Leading/trailing whitespace is allowed. No exception handling or room class is needed.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Missing hours; extra token; invalid interval; valid line after a rejected one.

<details>
<summary>One hint (open only if needed)</summary>

Use local variables while checking the record, then update the reference parameters.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
