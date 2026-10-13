# Deep Copy Matrix

**Level: Hard**

Build a resizable two-dimensional object that owns one allocation and remains independent when copied.

## Requirements

- Matrix(rows,cols) stores zero-initialized integers in one contiguous dynamic array. Negative dimensions throw std::invalid_argument("Negative dimension"); zero in either dimension is valid. Assume dimension products fit int.
- at(row,col), including its const overload, checks both dimensions and throws std::out_of_range("Cell out of range").
- resize(newRows,newCols) preserves values in the rectangular overlap of old and new dimensions, sets all other cells to zero, and releases old storage. Invalid dimensions leave the matrix unchanged.
- Implement the destructor, deep-copy constructor and deep-copy assignment operator. Assignment returns *this and supports self-assignment. Copying must not share storage.
- Allocation failures may propagate, but assignment and resize must preserve the old object when allocating new storage fails. No move operations are required.
- Example: [[1,2,3],[4,5,6]] resized to 3x2 becomes [[1,2],[4,5],[0,0]].

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use one new[] allocation per nonempty matrix, no vector or array containers. No memcpy. This exercise introduces the rule of three; consult its meaning if needed.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Copy empty matrix; assign different dimensions; self-assignment; grow and shrink both dimensions.

<details>
<summary>One hint (open only if needed)</summary>

The same (row,col) can have a different linear index after the column count changes.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
