# Resizable Integer Vector

**Level: Medium**

Extend a dynamic array with separate logical size and allocated capacity, close to the Library MyVector assignment.

## Requirements

- IntVector(n) has size and capacity n and zero-initializes all n elements. Negative sizes throw std::out_of_range("Negative size"). Zero is valid.
- resize(n): shrinking changes logical size only. Growing within capacity preserves existing logical elements and sets newly exposed elements to zero. Growing beyond capacity allocates exactly n slots, preserves old logical elements, zeroes the new ones, and releases the old allocation.
- reserve(n) increases capacity to exactly n only when n > current capacity; size and values do not change. Negative n throws std::out_of_range("Negative size").
- at(index) returns a writable reference and checks logical size, not capacity; invalid index throws std::out_of_range("Index out of range").
- On validation errors, size, capacity and contents stay unchanged. No memory leaks. Copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Internal storage must be a raw dynamic array; no realloc or containers. vector only for toVector result.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Reserve less than current capacity; shrinking to zero; grow after shrinking; zero-sized construction.

<details>
<summary>One hint (open only if needed)</summary>

Allocated capacity describes storage; logical size describes accessible elements.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
