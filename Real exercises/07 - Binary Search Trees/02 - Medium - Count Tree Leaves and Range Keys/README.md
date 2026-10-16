# Count Tree Leaves and Range Keys

**Level: Medium**

Add two small recursive summaries to supplied tree code.

## Requirements

- Existing Tree storage, insert and destruction are provided; duplicates are ignored.
- leafCount() counts nodes with no children, returning zero for empty tree.
- countBetween(low,high) counts keys in the inclusive range; low > high returns zero. Visiting every node is allowed.
- Implement these queries and your own private recursive helpers. No pruning-efficiency requirement or sum query.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use recursive helpers. Do not modify the supplied insert/destructor.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Singleton; one-sided tree; inclusive endpoints; inverted range.

<details>
<summary>One hint (open only if needed)</summary>

A leaf is a node with neither a left nor a right child.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
