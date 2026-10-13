# Tree Paths and Balance

**Level: Medium**

Compute properties that depend on tree shape and return the path between two stored keys.

## Requirements

- PathTree is an unbalanced BST of distinct keys; duplicate insertions do nothing.
- isHeightBalanced returns true when, at every node, the left and right subtree heights differ by at most one. Empty tree is balanced. Compute this in O(n), without repeatedly recalculating the same subtree heights.
- diameter returns the maximum number of NODES on any simple path between two nodes; empty tree 0, singleton 1. It need not pass through the root. Compute it in O(n).
- pathBetween(a,b) returns the key sequence from a to b along tree links. If either key is absent, throw std::out_of_range("Missing key"). A path from an existing key to itself contains that key once.
- Destructor frees the tree; copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Private dynamic nodes; no parent pointers required. Vectors allowed for paths, not tree storage.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty tree; skewed tree; longest path away from root; ancestor/descendant endpoints; missing endpoint.

<details>
<summary>One hint (open only if needed)</summary>

A recursive helper can return height while reporting another result through a reference parameter.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
