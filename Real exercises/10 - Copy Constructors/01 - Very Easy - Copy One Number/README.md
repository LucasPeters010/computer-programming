# Copy One Number

**Level: Very Easy | Exercise 1/8 | Topic: copy constructors**

## Your task

Copy the one integer field from the existing Counter into the new Counter.

Implement only `Counter::Counter(const Counter& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
Counter a(7);
Counter b(a);
b.set(9);
// a.get() is 7; b.get() is 9.
```

## What is checked automatically

- Zero, positive and negative values, integer limits, const source and independent changes.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

`other` is the existing object. `other.value` reads its value; `value` is the new object's field. There is no dynamic memory.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
