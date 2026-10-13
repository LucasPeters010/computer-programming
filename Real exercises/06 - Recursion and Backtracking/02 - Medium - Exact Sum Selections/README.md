# Exact Sum Selections

**Level: Medium**

Generate every index selection whose values total a target using recursive choices.

## Requirements

- exactSelections returns all selections of indices whose selected values sum exactly to target. Values and target are nonnegative integers; assume at most 20 values and sums fit int.
- Each index may appear at most once and indices inside each selection must be increasing. Equal values at different indices represent different selections.
- Include the empty selection when target is zero, and include any other valid selections containing zero-valued elements. Thus {0,0}, target 0 has four selections.
- Sort the final vector of selections lexicographically (std::sort on the result is allowed). Do not modify the input.
- Use recursive backtracking; no bit-mask enumeration or dynamic programming.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Local helpers and vectors allowed. No global state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Duplicate values; target zero; zero-valued elements; no solution; empty input.

## Algorithm outline

```text
search(next index, current sum, selected indices):
    if every index has been considered:
        record the selection if its sum is the target
    otherwise explore the choices of excluding or including this index
    restore the partial selection before exploring a different branch
```

Translate the idea into your own representation and helpers; this is not a C++ implementation recipe.

<details>
<summary>One hint (open only if needed)</summary>

Reaching the target is not necessarily the end when unprocessed zero values remain.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
