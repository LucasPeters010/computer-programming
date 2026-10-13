# One Route Through a Grid

**Level: Medium**

Find a route through a maze-like grid using recursive backtracking, similar to the Library path-finding task.

## Requirements

- Grid is a nonempty rectangular vector of strings containing . for open cells and # for walls, at most 15x15. Coordinates passed to findRoute are always in bounds.
- Find a route from (startRow,startCol) to (endRow,endCol) using orthogonal movement through open cells. Do not revisit a cell on a route.
- Return coordinate strings "row,col" including both endpoints, or an empty vector when no route exists. A blocked start or destination has no route.
- Explore neighbours in this order: right, down, left, up. Return the first route found, not necessarily the shortest.
- Use recursive backtracking. A start equal to an open destination produces a one-cell route. Leave the grid unchanged.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No pointers, arrays, structs or BFS; vectors and private/local recursive helpers are allowed.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Cycles in open areas; dead ends; same endpoints; blocked start; no route.

## Algorithm outline

```text
search(cell):
    reject a wall or a cell already on the current route
    add cell to the current route
    if cell is the destination, report success
    recursively try reachable neighbours in the required order
    if none succeeds, undo this cell's contribution and report failure
```

Translate the idea into your own representation and helpers; this is not a C++ implementation recipe.

<details>
<summary>One hint (open only if needed)</summary>

The route returned to the caller must not include a branch that reached a dead end.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
