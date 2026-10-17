# Copy a Vector of Scores

**Level: Easy | Exercise 6/8 | Topic: copy constructors**

## Your task

Copy the std::vector field, preserving size, values and order. Let std::vector manage its memory; do not use new or delete.

Implement only `ScoreList::ScoreList(const ScoreList& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
ScoreList a({8, 4, 6});
ScoreList b(a);
b.add(1);
// a.size() is 3; b.size() is 4.
```

## What is checked automatically

- Empty and singleton vectors, duplicates, negative values, order, appending, independent elements and copy of copy.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

Unlike an int* pointer, std::vector already knows how to copy its elements into independent storage. Copying the field is enough.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
