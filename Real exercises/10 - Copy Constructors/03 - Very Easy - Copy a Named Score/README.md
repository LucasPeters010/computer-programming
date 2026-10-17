# Copy a Named Score

**Level: Very Easy | Exercise 3/8 | Topic: copy constructors**

## Your task

Copy the name and score. A std::string already manages its own copying; do not allocate memory yourself.

Implement only `NamedScore::NamedScore(const NamedScore& other)` in `solution.cpp`.
The normal constructor, destructor (where needed), and accessors are supplied in `exercise.hpp`.
Keep the supplied fields and signatures. No printing from your constructor.
Copy assignment is deliberately disabled; it is a different exercise.

## Example

```cpp
NamedScore a("Lucas", 80);
NamedScore b(a);
b.set("Karim", 90);
// a still contains "Lucas" and 80.
```

## What is checked automatically

- Empty names, spaces, long names, negative scores, const sources and independent strings.

Run `main.cpp` and `solution.cpp` together. The starter builds and reports
`Not finished: Not implemented`; replace that throw with your work.
Success prints `All example and edge-case checks passed.`
The checks run on every launch; you do not need to add edge cases yourself.

<details>
<summary>Small hint</summary>

Copy the string field like the integer field. In normal production code the compiler-generated copy constructor would already handle these fields; here you write it to practise the syntax.

</details>

## Run

Open this folder's `solution.cpp` and use the configured C++ play button.
Or run from this exercise folder in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. Continue in numbered order; see the chapter README for the concepts.
