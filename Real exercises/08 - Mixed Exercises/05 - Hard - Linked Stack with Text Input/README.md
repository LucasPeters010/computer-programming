# Linked Stack with Text Input

**Level: Hard**

Combine core linked storage and strict parsing without extra business rules.

## Requirements

- TextStack stores integers in linked nodes: push adds, pop removes/returns, empty reports whether any node remains. Empty pop throws std::runtime_error("Stack is empty"). Destructor deletes nodes; copying disabled.
- loadNumbers(input,stack) reads physical lines, each containing exactly one integer with surrounding whitespace allowed. Valid lines are pushed in order. A malformed line throws std::runtime_error("Invalid line") and stops.
- Earlier valid lines REMAIN in the stack after a later error. No atomic rollback, custom exception types or output formatting.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: linked stack + streams + exceptions.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Blank line; extra number on line; invalid line after valid ones; cleanup after failure.

<details>
<summary>One hint (open only if needed)</summary>

The parser does not own the stack; it uses the stack interface.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
