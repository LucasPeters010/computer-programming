# Exam 1 - Checked Integer Stack

**Level: Final Exam**

Combine an owning stack, exceptions and a compact command interface.

Suggested practice time: **90 minutes**. This is an original practice task, not an official VU exam or a prediction of its exact scope.

## Requirements

- ExamStack(capacity) receives capacity >= 0 and owns an array of exactly that many ints. push adds unless full, throwing std::runtime_error("Stack is full"). pop removes/returns and top reads; empty pop/top throw std::runtime_error("Stack is empty").
- size() reports stored values. Destructor releases storage; copying disabled. No resizing.
- runStack(input,output,capacity) creates one stack and processes physical lines PUSH n, POP, TOP, SIZE. Exact integer arguments and no extra tokens are required.
- PUSH succeeds silently; other commands print their result and newline. Bad syntax prints Error: Invalid command. Stack errors print Error: MESSAGE. Every error line ends in newline and processing continues.
- Parse before changing stack state. Blank lines are invalid. Do not implement undo, batch processing or custom exception classes.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Raw array storage required. 90-minute original exam-style practice, not an official exam or a claim about exam coverage.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Capacity zero; push after pop; malformed command while full; empty errors.

## Self-marking rubric (100 points)

- Array ownership and cleanup: 20 points
- Stack operations and bounds: 30 points
- Command parsing: 25 points
- Error handling and recovery: 25 points

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
