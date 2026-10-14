# Simple Receipt

**Level: Medium**

Read several valid records and calculate totals.

## Requirements

- Input consists of zero or more valid lines NAME QUANTITY UNIT_CENTS. Names are single tokens, quantity > 0, unit cents >= 0; arithmetic fits int.
- writeReceipt prints NAME: TOTAL for each item, where TOTAL is quantity times unit cents expressed in euros with two decimals. End each row with newline.
- Finish with Total: GRAND_TOTAL and newline, including when input is empty.
- Example Apples 3 150 produces Apples: 4.50 then Total: 4.50. No table widths, delimiter parsing or error handling.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: No records; free item; several records; totals ending in zero cents.

<details>
<summary>One hint (open only if needed)</summary>

Calculate using integer cents, then convert for display.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
