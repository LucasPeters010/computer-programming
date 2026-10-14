# Named Score Line

**Level: Easy**

Use a string stream to summarize one record.

## Requirements

- summarize(line) receives valid input: one single-token name followed by at least one integer score. Values are 0..100.
- Return NAME: N scores, average A with A fixed to one decimal place and no newline.
- Example: Mila 60 81 becomes Mila: 2 scores, average 70.5.
- Use istringstream and ostringstream. No malformed-input handling or multiple-line processing yet.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: One score; several scores; trailing whitespace; average with a decimal fraction.

<details>
<summary>One hint (open only if needed)</summary>

Read the name once, then extract scores until the stream has no more.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
