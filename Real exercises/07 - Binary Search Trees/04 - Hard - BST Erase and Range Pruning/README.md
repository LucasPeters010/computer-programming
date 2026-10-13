# BST Erase and Range Pruning

**Level: Hard**

Extend a BST with safe deletion, including nodes with two children and removal of whole out-of-range regions.

## Requirements

- MutableTree stores distinct keys, ignoring duplicate inserts. erase(key) removes that key and returns whether it existed.
- Handle deletion of leaves, one-child nodes and two-child nodes. For a two-child deletion, use the in-order successor (minimum in the right subtree) as replacement.
- retainRange(low,high) deletes all keys outside the inclusive range and returns the number removed. If low > high, delete everything. Traverse/prune recursively in O(n); do not collect keys and repeatedly call erase.
- size reports stored node count, inOrder returns ascending keys, and height uses empty=0, singleton=1.
- Preserve BST ordering and correct ownership after every operation. Destructor releases remaining nodes; copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Raw dynamic nodes. No STL containers for storage or deletion planning; vector only for inOrder result.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Delete root repeatedly; successor with a child; prune all/none; empty tree; destructor after pruning.

<details>
<summary>One hint (open only if needed)</summary>

A subtree operation may replace the root of that subtree; design its interface accordingly.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
