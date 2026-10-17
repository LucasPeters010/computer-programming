# Copy Two Coordinates

**Level: Very Easy | Exercise 2/8 | Topic: copy constructors**

## Your task

Copy both coordinates exactly; do not reset them or swap them.

Implement only `Point::Point(const Point& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
Point a(4, -2);
Point b(a);
// b.getX() is 4; b.getY() is -2.
```

## What is checked automatically

- Different coordinates, zero, negative values, large values, both directions of independence and copy of a copy.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

Each field needs the corresponding field from `other`. A copy constructor can access private fields of another object of the same class.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
