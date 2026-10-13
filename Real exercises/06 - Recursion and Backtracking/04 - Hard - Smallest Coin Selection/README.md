# Smallest Coin Selection

**Level: Hard**

Search combinations with limited inventory and choose the best valid solution with a deterministic tie rule.

## Requirements

- chooseCoins receives positive coin values, one entry per available coin, and a nonnegative target. Assume at most 20 coins and sums fit int.
- Return indices of a subset totalling target, in increasing order. Use the fewest coins possible. If tied, choose the lexicographically smallest index vector.
- For target zero, return empty. When a positive target is impossible, throw std::runtime_error("No selection"). Duplicate values still represent distinct available coins.
- Implement recursive backtracking. Maintain the best complete candidate found so far; pruning is allowed but must not discard potential ties incorrectly.
- Do not change the input or reuse an index.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No dynamic programming, bit masks or global state. Vectors and ordinary loops inside recursion are allowed.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Impossible target; ties; exact one-coin solution; target zero; a greedy choice that fails.

<details>
<summary>One hint (open only if needed)</summary>

A larger coin is not always part of the best solution when each coin can be used only once.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
