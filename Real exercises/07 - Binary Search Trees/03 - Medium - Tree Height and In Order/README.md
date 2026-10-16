# Tree Height and In Order

**Level: Medium**

Implement two familiar traversals on a supplied BST.

## Requirements

- The BST infrastructure is provided, with distinct keys.
- height() returns zero for empty tree, one for a single node, and the maximum root-to-leaf node count otherwise.
- inOrder() returns a vector of ascending keys via recursive in-order traversal.
- Add private recursive helpers. No kth-smallest, floor, ceiling, path-between or diameter queries.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use recursion; do not sort the output vector afterward.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Singleton; ascending insertion chain; balanced tree; duplicate insertion.

<details>
<summary>One hint (open only if needed)</summary>

An in-order visit processes the left subtree, current key, then right subtree.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
