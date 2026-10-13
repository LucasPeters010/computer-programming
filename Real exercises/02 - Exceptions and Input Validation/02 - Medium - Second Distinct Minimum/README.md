# Second Distinct Minimum

**Level: Medium**

Replace ambiguous sentinel return values with custom exception objects carrying useful information.

## Requirements

- secondDistinctMinimum returns the second smallest DISTINCT integer in the vector without modifying it.
- If fewer than two values were supplied, throw TooFewValues carrying the actual count; count() exposes it.
- Otherwise, if all values are equal, throw NoDistinctValue carrying that repeated value; value() exposes it.
- These may be ordinary small classes; inheritance from std::exception is not required. A caller must be able to catch each type separately.
- Work in one pass, with a constant amount of additional storage. All int values, including INT_MIN and INT_MAX, are valid data.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No sorting, sets, maps or copying the input vector.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty vector; repeated minima; two distinct values in reverse order; extreme integers.

<details>
<summary>One hint (open only if needed)</summary>

Separate whether a candidate exists from the numerical value of that candidate.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
