# Linked Queue Core

**Level: Medium**

Move from a one-ended stack to a two-ended queue.

## Requirements

- Queue has FIFO push, front and pop; pop returns the removed integer. Empty front/pop throw std::runtime_error("Queue is empty").
- Node, first, last and the empty constructor are provided. Implement the three operations and destructor.
- An empty queue must have BOTH endpoint pointers null. push adds at the back and pop removes from the front.
- No transfer, cancellation, capacity limit or duplicate rules. Copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use dynamic nodes, no STL storage containers.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty queue; one node; alternating push/pop; destructor with remaining nodes.

<details>
<summary>One hint (open only if needed)</summary>

Removing the last remaining element is different from removing one of several.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
