# Owned Number Buffer

**Level: Easy**

Implement a small owning array class with checked access and overlapping shifts.

## Requirements

- NumberBuffer(n) allocates n integers initialized to zero. Negative n throws std::invalid_argument("Negative size"). Size zero is valid.
- Both at overloads check 0 <= index < size; otherwise throw std::out_of_range("Index out of range"). The non-const overload returns a writable reference.
- shiftRight(steps,fill) moves old values right by steps and fills newly exposed positions with fill. Values leaving the array are discarded. For steps >= size, fill the whole buffer. Negative steps throw std::invalid_argument("Negative shift") without changing data.
- Destructor releases the owned array. Copying is disabled in the supplied interface and is outside this exercise.
- toVector() returns the current values for inspection; it must not transfer ownership.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Store data in one new[] array and release with delete[]. No container for internal storage. shiftRight uses no additional array; vector allowed only for toVector result.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Size zero; shift zero; shift equal to size; access at -1; destruction after an exception.

<details>
<summary>One hint (open only if needed)</summary>

Think about whether the direction of a shift could overwrite values you still need.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
