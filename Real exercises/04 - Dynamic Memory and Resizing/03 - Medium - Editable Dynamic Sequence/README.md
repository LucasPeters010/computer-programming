# Editable Dynamic Sequence

**Level: Medium**

Implement insertion and erasure while handling both unused capacity and allocation growth.

## Requirements

- IntSequence starts empty with capacity 0. insert(index,value) accepts 0 <= index <= size; otherwise throw std::out_of_range("Index out of range").
- If insertion requires more storage, capacity becomes 1 from zero or doubles otherwise. Preserve order and every old value. Without growth, shift within the existing allocation.
- erase(index) removes and returns the value at 0 <= index < size; capacity does not shrink. Invalid index throws the same error.
- eraseRange(first,last) removes the half-open range [first,last). Require 0 <= first <= last <= size; invalid ranges throw std::out_of_range("Invalid range"). An empty range is a no-op.
- Validation errors leave the sequence unchanged. Destructor releases memory. Copying is disabled. size(), capacity(), and toVector() inspect state.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use new[] and delete[]; no containers for internal storage. No allocation during erasure. vector only for toVector result.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Insert into empty sequence; append; erase last value; erase entire range; no-op range.

<details>
<summary>One hint (open only if needed)</summary>

Describe how indices change on paper for insertion at the beginning and erasure in the middle.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
