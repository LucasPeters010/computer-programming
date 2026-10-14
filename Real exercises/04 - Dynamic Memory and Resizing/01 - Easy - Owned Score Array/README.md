# Owned Score Array

**Level: Easy**

Own one array and implement checked access plus a summary.

## Requirements

- ScoreArray(n) receives n >= 0; allocate n integers initialized to zero. Destructor releases the array.
- at(index) returns a writable int reference; invalid index throws std::out_of_range("Invalid index"). sum() returns the total (assume it fits int).
- size is fixed; no resizing, copying, shifting or const at overload. Copying is disabled by the starter.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use the supplied pointer and length fields; no vector for storage.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Zero length; first/last index; negative index; changing an element through at.

<details>
<summary>One hint (open only if needed)</summary>

Allocate with new[] and release with delete[]. The stored length defines valid indices.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
