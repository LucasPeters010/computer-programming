# Undoable Calculator Log

**Level: Medium**

Combine classes, a vector-backed history, strict stream parsing and recoverable errors.

## Requirements

- Calculator starts at zero. execute(line) accepts exactly ADD n, MUL n, UNDO, or PRINT, allowing surrounding whitespace. n is an int; assume arithmetic results fit int.
- ADD and MUL save the previous value even if the result is unchanged, update the value, and return an empty string. UNDO restores and removes the latest saved value; it creates no new history entry and returns empty.
- PRINT returns the current value as text, without newline. Invalid grammar throws std::runtime_error("Invalid command"). UNDO with no history throws std::runtime_error("Nothing to undo").
- runCalculator uses one Calculator for all physical lines. Print each nonempty response followed by newline; on runtime_error print ERROR: MESSAGE followed by newline and continue. Blank lines are invalid commands.
- Errors must not change either current value or history. value() exposes the current value.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use vector for history; no raw pointers. Focus: classes + streams + exceptions + stack behaviour.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Repeated PRINT; ADD 0; multiply by zero then undo; invalid command after valid operations.

<details>
<summary>One hint (open only if needed)</summary>

Parsing a command and applying it are separate responsibilities.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
