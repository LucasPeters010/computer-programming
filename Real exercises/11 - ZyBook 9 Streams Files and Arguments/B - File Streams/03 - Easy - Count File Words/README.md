# Count File Words

**Easy | Part B, exercise 3 | ZyBook 9.5**

## Goal and exact requirements

Use an ifstream and a successful-extraction loop to count whitespace-separated words. Empty input gives 0. Opening failure throws runtime_error("Cannot open"). Assume readable regular text files after opening and word count fits int.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

A file containing `red blue` on one line and `red` on another returns 3.

<details>
<summary>Small steps / hint</summary>

Use a string for each word. Increment only when input >> word succeeds.

</details>

## Automatic checks

main.cpp already runs example and edge cases, including empty input, boundaries,
and invalid input where the requirements allow it. Inputs guaranteed valid are
not secretly tested as invalid. The starter compiles but reports Not implemented.
Success prints `All example and edge-case checks passed.`
The supplied test_support.hpp is test machinery, not coursework to implement.

Tests create and remove their own temporary files automatically. You do not need to create test files manually.

## Build and run the tests

Open this folder's solution.cpp and use the configured C++ play button.
Or open a PowerShell terminal IN THIS EXERCISE FOLDER and run:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

On Linux/macOS use ./solution instead of .\solution.exe and compile with -o solution.
Do not compile the header by itself; both .cpp files are required.
