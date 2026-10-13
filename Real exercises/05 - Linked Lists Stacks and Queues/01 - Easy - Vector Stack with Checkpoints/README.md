# Vector Stack with Checkpoints

**Level: Easy**

Implement a vector-backed stack with an interface comparable to the Library Stack assignment, plus rollback.

## Requirements

- push adds an integer. top reads it; pop returns and removes it. Empty top/pop throw std::runtime_error("Stack is empty").
- mark() returns the current stack size. rollback(mark) removes newer elements until that size is restored; require 0 <= mark <= current size, otherwise throw std::out_of_range("Invalid checkpoint").
- Checkpoints are sizes, not saved copies: you cannot restore values already popped. A mark can be reused if its numerical value is still valid.
- toString returns [top,next,...,bottom] with no spaces, or [] when empty. size and isEmpty inspect the stack.
- Invalid rollback must not change the stack.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use std::vector internally; no std::stack or raw pointers.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Rollback current size; rollback empty stack to zero; invalid mark; pop followed by rollback.

<details>
<summary>One hint (open only if needed)</summary>

A checkpoint describes a valid stack depth, not a separate stack.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
