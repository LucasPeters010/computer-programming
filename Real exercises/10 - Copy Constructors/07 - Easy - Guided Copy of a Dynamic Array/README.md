# Guided Copy of a Dynamic Array

**Level: Easy | Exercise 7/8 | Topic: copy constructors**

## Your task

Copy a dynamic array of any length. Assume n >= 0. Preserve length and every value; own a new array. For length 0, keep data == nullptr.

Implement only `NumberArray::NumberArray(const NumberArray& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
NumberArray a(2);
a.at(0) = 8; a.at(1) = 4;
NumberArray b(a);
b.at(0) = 99;
// a.at(0) is still 8; b.size() is 2.
```

## What is checked automatically

- Empty, single-element and longer arrays, all elements, duplicates, negatives, source lifetime, const source and independent modifications.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

Follow these small steps:
1. Copy `other.length` into `length`.
2. If length is zero, leave data as nullptr.
3. Otherwise allocate length integers.
4. Loop from 0 while i < length, copying each source element.

This is guided preparation for the website's medium vector-copy task.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
