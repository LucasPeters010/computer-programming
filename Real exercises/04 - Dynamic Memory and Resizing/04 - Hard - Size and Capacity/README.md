# Size and Capacity

**Level: Hard**

Add retained capacity to a small resizable vector.

## Requirements

- MiniVector starts empty with size=capacity=0. resize(n) sets logical size. Negative n throws std::invalid_argument("Negative size").
- If n exceeds capacity, allocate exactly n slots, preserve old logical elements and release old memory. Otherwise retain the existing allocation.
- Newly exposed logical elements are zeroed, including after shrink then grow. Shrinking never reduces capacity.
- at(index) returns a writable reference and validates against size, throwing std::out_of_range("Invalid index"). size() and capacity() inspect state.
- Destructor frees memory; copying disabled. No reserve, insert, erase, copy assignment or matrix.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Raw array storage only. This is a reduced version of Library MyVector.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Zero size; grow within capacity; grow beyond capacity; invalid resize.

<details>
<summary>One hint (open only if needed)</summary>

Storage that still exists after shrinking is not necessarily a valid logical element.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
