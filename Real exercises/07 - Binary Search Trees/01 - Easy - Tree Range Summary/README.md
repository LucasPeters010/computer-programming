# Tree Range Summary

**Level: Easy**

Build an integer BST and compute structural summaries with recursive helpers.

## Requirements

- SummaryTree stores each distinct key once; insert returns false for a duplicate and true for a new node. Do not rebalance the tree.
- contains reports membership. sum returns the sum of all stored keys; leafCount counts nodes with no children. Empty tree: both zero.
- rangeSum(low,high) returns the sum of keys in the inclusive range, or zero if low > high. Avoid visiting subtrees whose keys cannot be in range.
- Use long long for sums. Each node is dynamically allocated and destroyed exactly once. Define your private node class and recursive helpers.
- Copying is disabled. Implement insertion, membership and the three summaries recursively.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Raw dynamic nodes required; no arrays or STL containers for tree storage.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty tree; one node; ascending inserts; negative keys; duplicates; inverted range.

<details>
<summary>One hint (open only if needed)</summary>

For each recursive summary, define the empty-subtree result first.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
