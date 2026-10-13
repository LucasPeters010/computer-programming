# Invoice Formatter

**Level: Medium**

Read a small delimited format and print aligned invoice rows using integer cents.

## Requirements

- Each line is NAME;QUANTITY;UNIT_CENTS, with exactly two semicolons. NAME is 1..12 characters, contains no semicolon or leading/trailing whitespace, and may contain internal spaces.
- Quantity and unit cents are complete integer fields, allowing surrounding whitespace. Quantity > 0, unit cents >= 0. Assume valid arithmetic fits int.
- Reject invalid lines and count them. Valid rows are printed in input order: name left-aligned in width 12, then one space, quantity right-aligned in width 3, then one space, line total in euros right-aligned in width 8 with exactly two decimals. Every row ends with newline.
- Finish with TOTAL followed by one space and the unpadded euro total to two decimals, then newline. Empty input still prints TOTAL 0.00.
- Do not include a currency symbol. Do not emit a partial row on error.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Extra delimiter; multiword name; numeric suffix such as 12x; free item; long name.

<details>
<summary>One hint (open only if needed)</summary>

Keep money in cents while calculating; formatting is a separate responsibility.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
