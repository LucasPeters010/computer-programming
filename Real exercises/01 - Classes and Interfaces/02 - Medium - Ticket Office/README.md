# Ticket Office

**Level: Medium**

Manage two related quantities in one class.

## Requirements

- TicketOffice(capacity) starts with all tickets available and none reserved; capacity is nonnegative.
- reserve(amount) succeeds only for amount > 0 and enough available tickets. cancel(amount) succeeds only for amount > 0 and enough reserved tickets. Return bool; rejected requests change nothing.
- available() and reserved() return the two counts. Cancelling restores available tickets.
- No individual customer IDs, collections, strings or exceptions are needed.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use standard C++17. You may add helpers. No hard-coded sample answers or global mutable state.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Zero/negative amount; reserve all; cancel all; capacity zero.

<details>
<summary>One hint (open only if needed)</summary>

After every successful operation, available plus reserved should equal the original capacity.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
