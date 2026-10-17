# Copy Three Owned Numbers

**Level: Easy | Exercise 5/8 | Topic: copy constructors**

## Your task

Allocate a separate array of exactly three integers and copy all three values in the same order.

Implement only `Triple::Triple(const Triple& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
Triple a(8, 4, 6);
Triple b(a);
b.at(1) = 100;
// a is still 8, 4, 6; b is 8, 100, 6.
```

## What is checked automatically

- All positions, negative/zero/duplicate/extreme values, separate storage, const copying and destruction independence.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

The array size is always 3. First allocate it, then copy positions 0, 1 and 2 with a loop. Do not delete the source array.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
