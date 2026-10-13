# Postfix Expression Evaluator

**Level: Hard**

Combine strict token parsing, a manually resized stack and expression error handling.

## Requirements

- ValueStack stores doubles in a dynamic array. It starts with capacity zero and grows to 1, then doubles whenever full. push adds; pop removes/returns; top inspects; empty pop/top throw std::runtime_error("Stack underflow"). size returns the count. Destructor frees the array; copying is disabled.
- evaluatePostfix accepts whitespace-separated finite decimal numbers and operators + - * /. A numeric token must be consumed completely; signs and scientific notation are allowed. A token exactly equal to an operator is an operator.
- For a binary operator, the earlier operand is the left operand: 8 2 / gives 4. Too few operands throw std::runtime_error("Missing operand"). Division by zero throws std::runtime_error("Division by zero"). Any other token throws std::runtime_error("Invalid token").
- Process tokens left to right; the first encountered error wins. At end require exactly one value or throw std::runtime_error("Incomplete expression"). Empty expression is incomplete. Assume successful arithmetic remains finite.
- evaluatePostfix must use ValueStack and clean up even when an error occurs.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No std::stack/vector for ValueStack storage. Focus: dynamic memory + stacks + streams + exceptions.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty expression; extra operands; division order; malformed number; stack destruction after a parse error.

<details>
<summary>One hint (open only if needed)</summary>

The numerical value -2 is one token; the operator - is a different token.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
