# Copy Size and Capacity

**Level: Medium | Exercise 8/8 | Topic: copy constructors**

## Your task

Deep-copy the buffer, preserving both its used size and allocated capacity. Assume capacity >= 0. Copy the used values in order. Capacity 0 means data == nullptr. An empty buffer may still have positive capacity.

Implement only `CopyBuffer::CopyBuffer(const CopyBuffer& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
CopyBuffer a(5);
a.push(8); a.push(4);
CopyBuffer b(a);
b.push(6);
// a.size() is 2; b.size() is 3; both capacities are 5.
```

## What is checked automatically

- Zero capacity, empty with spare capacity, singleton, partially full/full buffers, independent mutations and pushes, const copying and source destruction.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

Allocate space for capacity, but copy only size used elements. The supplied push writes an unused slot before reading it; unused slots do not have values you need to preserve.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
