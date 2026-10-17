# Open a File

**Very Easy | Part B, exercise 1 | ZyBook 9.5**

## Goal and exact requirements

Open filename for reading using ifstream and return whether it opened. Do not read any data or create a missing file. No exceptions required. The local stream closes when it leaves scope.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

Existing empty file: true. Missing file: false.

<details>
<summary>Small steps / hint</summary>

1. Declare std::ifstream.
2. Call open(filename).
3. Return is_open(). Nothing else yet.

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
