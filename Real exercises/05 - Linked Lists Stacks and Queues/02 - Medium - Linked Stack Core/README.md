# Linked Stack Core

**Level: Medium**

Implement three operations using a supplied node representation.

## Requirements

- LinkedStack has push, top and pop with LIFO behaviour. pop returns the removed value.
- Empty top/pop throw std::runtime_error("Stack is empty").
- Node, head, constructor and destructor are provided. Implement ONLY push, top and pop.
- Each push allocates one node. Each pop deletes exactly the removed node; Node itself does not delete next. No copying, size tracking or formatting.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use supplied private node class. Do not change the provided constructor/destructor.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: One node; multiple nodes; empty errors; destruction with nodes still stored.

<details>
<summary>One hint (open only if needed)</summary>

Keep a way to reach the remaining stack when removing its first node.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
