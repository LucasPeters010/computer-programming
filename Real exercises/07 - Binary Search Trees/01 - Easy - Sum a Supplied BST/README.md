# Sum a Supplied BST

**Level: Easy**

Add one recursive query to working tree storage, like the Library BST sum exercise.

## Requirements

- Tree insertion, node representation, constructor and destructor are provided. Duplicate keys are ignored.
- Implement sum() and its private recursive helper sumNodes(Node*). Empty subtree contributes zero. Use long long for the sum.
- Do not change existing tree operations. No range queries, balancing, traversal output or deletion task.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Only sum() and sumNodes() are your task; infrastructure is provided.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Empty tree; single node; negative keys; skewed tree.

<details>
<summary>One hint (open only if needed)</summary>

A subtree sum combines its own key and the results for its two children.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
