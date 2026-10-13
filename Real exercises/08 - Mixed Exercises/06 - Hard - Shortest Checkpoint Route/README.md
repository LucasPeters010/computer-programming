# Shortest Checkpoint Route

**Level: Hard**

Combine a grid class, recursive search and the requirement to visit a checkpoint before reaching the destination.

## Requirements

- RouteMap receives a nonempty rectangular grid of . and #, at most 5x5; constructor throws std::invalid_argument("Invalid grid") otherwise.
- shortestVia(checkRow,checkCol) finds the shortest simple route from top-left to bottom-right that visits the checkpoint. A cell may be visited at most once. Include endpoints and checkpoint once each in the returned coordinate strings "row,col".
- Invalid checkpoint coordinates throw std::out_of_range("Invalid checkpoint"). Blocked endpoints/checkpoint or no route return an empty vector.
- Use recursive backtracking to explore possible routes. Prefer fewer cells. For equal lengths, keep the first found when exploring right, down, left, up. Return immediately from a branch that reaches the destination: it may not leave and return later.
- Each call starts with fresh search state and must leave the map unchanged. rows and cols expose dimensions. A 1x1 open grid with checkpoint (0,0) has a one-cell route.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use recursive backtracking, no BFS or pointers. Vectors allowed. Focus: classes + recursion + backtracking + validation.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Checkpoint at either endpoint; blocked checkpoint; no simple route through checkpoint; multiple equal shortest routes.

<details>
<summary>One hint (open only if needed)</summary>

Finding the shortest start-to-checkpoint route and shortest checkpoint-to-end route separately can create repeated cells.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
