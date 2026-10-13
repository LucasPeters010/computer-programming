# Ordered Tree Queries

**Level: Medium**

Implement a BST interface that returns sorted values, height and neighbouring keys.

## Requirements

- OrderedTree stores distinct integer keys; insert ignores duplicates. inOrder returns all keys ascending. height is 0 for empty and 1 for a single node.
- kthSmallest(k) is zero-based and throws std::out_of_range("Invalid rank") when k < 0 or k >= node count. Implement using a recursive traversal; do not call inOrder to materialize all keys for this query.
- floorKey(key) returns the greatest stored key <= key, throwing std::out_of_range("No floor") if none exists.
- ceilingKey(key) returns the least stored key >= key, throwing std::out_of_range("No ceiling") if none exists.
- Do not rebalance. Destructor frees every node; copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Private dynamic node class. vector only for inOrder result; recursive helpers for traversal and height.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty tree queries; exact match; below minimum; above maximum; duplicate insertion.

<details>
<summary>One hint (open only if needed)</summary>

A failed search path can still carry the best floor or ceiling candidate seen so far.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
