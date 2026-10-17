# Report Valid Score Lines

**Hard | Part A, exercise 5 | ZyBook 9.3 / 9.7**

## Goal and exact requirements

Each physical line must contain exactly one int in 0..100, with surrounding whitespace allowed. For each bad line, write `Invalid line N` plus newline (N starts at 1), then continue. Blank lines are invalid. Finally write `Count: C` and `Total: T`, each followed by newline. Empty input gives count/total 0. Do not treat the final newline as an extra blank line. You may add a helper like A04; no files or command-line arguments here.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

Input:
```text
80
bad
20
```
Output:
```text
Invalid line 2
Count: 2
Total: 100
```

<details>
<summary>Small steps / hint</summary>

Use getline for the outer loop and a fresh istringstream for each line. A failed line must not leave the next line in a failed stream state.

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
