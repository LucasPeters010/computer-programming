# Sparse Polynomial List

**Level: Hard**

Combine a sorted linked representation, cancellation of terms and strict textual input.

## Requirements

- Polynomial stores terms coefficient*x^exponent, with nonzero integer coefficient and nonnegative integer exponent. Keep nodes in descending exponent order, one per exponent. Zero polynomial has no nodes.
- addTerm(coefficient,exponent) merges equal exponents and deletes the node if the resulting coefficient is zero. Zero coefficient is a no-op. Negative exponent throws std::invalid_argument("Negative exponent") even when coefficient is zero.
- addFrom(other) adds every term of other into this polynomial, leaving other unchanged. Self-addition doubles every coefficient correctly. Assume all arithmetic fits the relevant return type.
- evaluate(x) returns long long. terms returns text COEFF@EXP separated by single spaces, or 0 for the zero polynomial.
- load(input) REPLACES this polynomial from lines containing exactly two ints: coefficient exponent. Syntax error throws std::runtime_error("Malformed term"); negative exponent uses the addTerm error. On any invalid line preserve the original polynomial. Empty input clears it; blank lines are malformed.
- Destructor frees nodes. Copying is disabled; load must still be atomic without copying the owning object.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use dynamic linked nodes for polynomial storage. A temporary vector of parsed pairs is allowed during load only. No maps. Focus: linked lists + streams + exceptions.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Cancellation of head; repeated exponents; zero coefficient; self-addition; bad final input line.

<details>
<summary>One hint (open only if needed)</summary>

An atomic import can build a temporary ownership structure before replacing the old one.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
