# Tree Report from Input

**Level: Hard**

Combine supplied BST storage with your recursive queries and a small input/output function.

## Requirements

- ReportTree insertion, constructor, node representation and destructor are provided. Duplicate keys are ignored.
- Implement sum() recursively and inOrder() via recursive traversal.
- writeTreeReport reads valid whitespace-separated ints to EOF into a ReportTree. Print ascending keys separated by single spaces and newline, then Sum: TOTAL and newline. Empty input prints an empty first line and Sum: 0.
- No malformed-input handling, deletion or command language.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: trees + recursion + streams. Do not sort a vector instead of traversing the tree.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: No keys; duplicates; negative keys; sorted input.

<details>
<summary>One hint (open only if needed)</summary>

Build and query the tree through its public interface in the stream function.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
