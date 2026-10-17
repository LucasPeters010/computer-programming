# Read an Age

**Very Easy | Part A, exercise 1 | ZyBook 9.3**

## Goal and exact requirements

Use std::istringstream to read one first-name word followed by an age, then return the age. Input is guaranteed valid; age is 0..150. No error handling yet.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`readAge("Lucas 18")` returns `18`.

<details>
<summary>Small steps / hint</summary>

1. Construct an istringstream from line.
2. Declare a string and an int.
3. Extract them with >> in that order.
4. Return the int.

</details>

## Automatic checks

main.cpp already runs example and edge cases, including empty input, boundaries,
and invalid input where the requirements allow it. Inputs guaranteed valid are
not secretly tested as invalid. The starter compiles but reports Not implemented.
Success prints `All example and edge-case checks passed.`
The supplied test_support.hpp is test machinery, not coursework to implement.

## Build and run the tests

Open this folder's solution.cpp and use the configured C++ play button.
Or open a PowerShell terminal IN THIS EXERCISE FOLDER and run:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

On Linux/macOS use ./solution instead of .\solution.exe and compile with -o solution.
Do not compile the header by itself; both .cpp files are required.
