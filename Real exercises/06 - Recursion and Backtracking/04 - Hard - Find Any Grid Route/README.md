# Find Any Grid Route

**Level: Hard**

Use the Library-style backtracking idea for one small search.

## Requirements

- hasRoute(grid,row,col) reports whether you can reach the bottom-right cell from the supplied start using up/down/left/right moves through . cells. # means wall.
- grid is a nonempty rectangular vector of strings, at most 10x10. Return false for an out-of-bounds starting coordinate or blocked cell.
- Use recursive backtracking, temporarily marking cells to prevent revisits. Restore ALL changed cells before returning, whether successful or not.
- Return bool only; no shortest route, checkpoint, coordinate objects or printed path.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

No pointers, pairs or BFS. Use recursive backtracking.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Single open cell; blocked destination; cycles; failed search; repeat a search on the same grid.

## Algorithm outline

```text
Reject outside, wall or visited cells.
If at the destination, report success.
Mark this cell, recursively try neighbours, then restore this cell.
Report whether any neighbour led to success.
```

Translate the idea into your own representation and helpers; this is not a C++ implementation recipe.

<details>
<summary>One hint (open only if needed)</summary>

Restoration is needed on successful return paths as well as failed branches.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
