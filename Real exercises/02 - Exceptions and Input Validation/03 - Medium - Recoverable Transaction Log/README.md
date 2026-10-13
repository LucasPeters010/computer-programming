# Recoverable Transaction Log

**Level: Medium**

Process independent input lines while reporting errors and continuing after a bad transaction.

## Requirements

- TransactionError stores the 1-based physical line number and a message; line() and message() expose them.
- applyTransaction(balance,text,lineNumber) accepts exactly DEPOSIT n or WITHDRAW n, with n a positive integer amount in cents. Leading/trailing whitespace is allowed.
- Invalid grammar (including unknown command, missing amount, trailing tokens, or integer overflow while parsing) throws TransactionError(lineNumber,"Malformed transaction"). A parsed amount <= 0 throws "Amount must be positive"; overdraft throws "Insufficient funds". Error priority is grammar, positive amount, funds.
- Return the new balance on success. Preconditions: balance >= 0; successful arithmetic fits int.
- processLog reads every physical line, starting with balance 0. It catches TransactionError per line, prints LINE: MESSAGE followed by newline to the supplied error stream, and continues. A blank line is malformed. Return the final balance.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty file; blank lines; malformed amount; withdrawing exactly the balance; valid lines after an error.

<details>
<summary>One hint (open only if needed)</summary>

Choose the catch location so that one invalid line does not end the entire log.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
