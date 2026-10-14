# Small Command Reader

**Level: Hard**

Parse a tiny command language with exact output.

## Requirements

- runCommands starts an integer total at zero. Each physical line is ADD n, RESET, or SHOW. n must be an int; no extra tokens are allowed. Assume addition fits int.
- ADD changes the total silently, RESET sets it to zero silently, SHOW prints the total and newline.
- Unknown, blank or malformed lines print Invalid command and newline, leave the total unchanged, and processing continues.
- Surrounding whitespace is allowed. No classes, history, undo or custom exceptions.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: ADD negative number; RESET with extra token; empty line; SHOW before any ADD.

<details>
<summary>One hint (open only if needed)</summary>

Validate the entire line before changing the total.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
