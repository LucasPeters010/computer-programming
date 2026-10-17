# Copy One Owned Integer

**Level: Easy | Exercise 4/8 | Topic: copy constructors**

## Your task

Allocate one new integer for the copy and give it the source integer's value. Each IntBox must own a different allocation.

Implement only `IntBox::IntBox(const IntBox& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
IntBox a(7);
IntBox b(a);
b.at() = 99;
// a.at() is 7; b.at() is 99.
```

## What is checked automatically

- Zero, negatives, const sources, different addresses, mutations both ways, copy of copy and surviving source destruction.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

`other.data` is an address; `*other.data` is the number there. Copy the number into newly allocated memory. The supplied destructor uses `delete` because this is one int, not an array.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
