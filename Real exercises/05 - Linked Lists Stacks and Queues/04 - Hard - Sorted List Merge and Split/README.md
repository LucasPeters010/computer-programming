# Sorted List Merge and Split

**Level: Hard**

Maintain a sorted linked structure while moving ownership between lists using only pointer changes.

## Requirements

- SortedList stores ascending integers, allowing duplicates. insert(value) creates one node in the correct place. size and toVector inspect it.
- mergeFrom(other) moves every node from other into this list, preserving ascending order; other becomes empty. Equal values originally in this list come before equal values from other. Self-merge is a no-op.
- splitAt(pivot,destination) moves every value >= pivot into destination in order. Destination must be a different, empty list; otherwise throw std::invalid_argument("Invalid destination") before changing either list.
- mergeFrom runs in O(n+m), splitAt in O(n). Neither may allocate or delete any nodes, copy nodes, or implement the operation by repeated insertion.
- Each list owns its nodes and frees them in its destructor. Copying is disabled. Do not return owning lists by value.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Private node class and raw pointers only for storage. vector only for inspection.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Merge empty lists; all equal values; split none/all; invalid destination; destruction of both outputs.

<details>
<summary>One hint (open only if needed)</summary>

Reason about ownership of the remaining suffixes before changing any links.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
