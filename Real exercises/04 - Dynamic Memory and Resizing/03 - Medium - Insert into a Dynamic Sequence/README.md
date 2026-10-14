# Insert into a Dynamic Sequence

**Level: Medium**

Shift and resize storage for one insertion operation.

## Requirements

- Sequence starts empty. insert(index,value) accepts 0 <= index <= size and inserts before that position; index==size appends.
- Invalid index throws std::out_of_range("Invalid index") without changes. at(index) returns a value for 0 <= index < size or throws the same error.
- size() reports the number of elements. Allocating exactly size+1 on each insert is allowed.
- Destructor releases memory; copying is disabled. No erase, capacity policy or range operations.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use a raw dynamic array, no vector or realloc.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Insert first/last; insert into empty sequence; invalid index; several insertions.

<details>
<summary>One hint (open only if needed)</summary>

Draw where each old index should land relative to the inserted value.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
