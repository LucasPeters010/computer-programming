# Keep Reading After Errors

**Level: Medium**

Recover per line instead of stopping after one invalid entry.

## Requirements

- readScore(line) accepts exactly one integer 0..100 with optional surrounding whitespace. Missing/noninteger input or extra tokens throws std::runtime_error("Bad input"); an out-of-range parsed integer throws std::out_of_range("Bad score"). Check syntax before range.
- collectScores(input,errors) reads physical lines. Valid scores are returned in a vector in input order. On either error, write the exception message followed by newline to errors, then continue.
- Blank lines are bad input. Integer overflow during extraction is bad input. No line numbers or custom exception class.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Automatically tested in main.cpp: Empty file; blank line; bad line between good ones; out-of-range value with trailing garbage.
Also covered: boundary and extreme values, exact exception payloads/messages, and relevant input-preservation or parser-recovery cases. No manual additions are needed to run these checks.

<details>
<summary>One hint (open only if needed)</summary>

The try/catch belongs inside the loop that processes lines.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the automatic checks; optional extra cases are welcome. Do not commit executables.
