# Basic Vector Stack

**Level: Easy**

Implement a small stack interface comparable to the core of the Library Stack.

## Requirements

- IntStack starts empty. push(value) adds at the top; pop() removes and returns the latest value; top() returns it without removal.
- Empty top/pop throw std::runtime_error("Stack is empty"). isEmpty() reports whether any values are stored.
- No string conversion, checkpoints, rollback, raw pointers or input parser.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use the supplied vector field, not std::stack.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: One element; pop until empty; reuse an emptied stack.

<details>
<summary>One hint (open only if needed)</summary>

The last element of the vector is the top of this stack.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
