# Warehouse Orders

**Level: Medium**

Design two cooperating classes that reserve and release stock without letting quantities become inconsistent.

## Requirements

- StockItem starts with an SKU and nonnegative quantity. available() excludes reserved units; reserved() counts them.
- reserve(q) succeeds only for q > 0 and enough available stock. release(q) succeeds only for q > 0 and q <= reserved stock. Both return bool and leave state unchanged on failure.
- dispatch(q) removes q reserved units permanently; it returns false if q <= 0 or insufficient units are reserved. Dispatching must not reduce available stock again.
- Warehouse stores items with unique SKUs. addItem returns false for duplicate SKUs or negative quantity. reserve/release/dispatch return false for an unknown SKU.
- report() lists insertion order as SKU available/reserved, one item per line with a trailing newline. Empty warehouse: empty string.
- A directly constructed StockItem receives a nonnegative quantity (precondition).

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Warehouse must contain StockItem objects in a vector. No raw pointers or public data fields.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Zero and negative requests; dispatch all reserved units; repeated SKU; reservation that fails.

<details>
<summary>One hint (open only if needed)</summary>

Decide which class owns each rule; Warehouse should use StockItem operations.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
