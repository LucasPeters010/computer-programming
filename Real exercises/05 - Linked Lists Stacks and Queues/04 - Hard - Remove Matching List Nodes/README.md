# Remove Matching List Nodes

**Level: Hard**

Delete matching nodes throughout a linked list.

## Requirements

- IntList stores a singly linked chain. append(value) adds at the end; removeAll(value) deletes every matching node and returns how many were removed.
- toVector returns remaining values from head to tail. Preserve their relative order. Destructor deletes remaining nodes.
- Node and head are supplied; you implement the constructor and methods. Copying is disabled.
- No reversal, merge, split or transfer. removeAll must not allocate replacement nodes.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Raw linked nodes; vector only for the returned inspection result.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Every node matches; none matches; head/tail matches; consecutive matches.

<details>
<summary>One hint (open only if needed)</summary>

After a deletion, consider whether the next node also matches before advancing.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
