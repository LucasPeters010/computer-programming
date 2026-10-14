# Recursive Binary Search

**Level: Medium**

Use recursion to choose one half of a sorted range.

## Requirements

- binarySearch(values,target,left,right) searches the inclusive index range [left,right] in an ascending vector of DISTINCT integers.
- Return the matching index or -1. An empty range (left > right) has no match. Call with left=0, right=int(values.size())-1 for the full vector.
- Use recursion, not a loop or std::binary_search. Aside from an empty range, indices are valid. Do not copy the vector.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

No loops, standard search algorithms or global state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: First/last element; singleton; absent value between elements; empty range.

## Algorithm outline

```text
If the range is empty, report missing.
Compare the target with the middle value.
If unequal, recursively search only the relevant half.
```

Translate the idea into your own representation and helpers; this is not a C++ implementation recipe.

<details>
<summary>One hint (open only if needed)</summary>

Ensure the next range excludes the middle element you already checked.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
