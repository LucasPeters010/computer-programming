# Build a Small BST

**Level: Hard**

Implement the core tree operations yourself.

## Requirements

- SearchTree starts empty and uses the supplied private Node class and root pointer. insert(key) adds a key if absent; duplicates do nothing.
- contains(key) reports membership. inOrder() returns sorted keys by recursive traversal.
- Implement constructor, destructor and these operations. Destructor frees every node. Copying is disabled.
- No balancing, erasure, range pruning, height, floor or rank queries.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use raw dynamic tree nodes; vector only for inOrder output.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty tree; root match; missing key; duplicates; skewed insertion order.

<details>
<summary>One hint (open only if needed)</summary>

You may add helper functions taking a Node pointer or a reference to one.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
