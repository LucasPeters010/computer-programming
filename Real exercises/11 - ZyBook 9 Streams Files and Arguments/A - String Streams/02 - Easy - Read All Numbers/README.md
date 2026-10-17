# Read All Numbers

**Easy | Part A, exercise 2 | ZyBook 9.3**

## Goal and exact requirements

Use an istringstream and an extraction-controlled loop to return the sum of all integers. Empty/whitespace-only input returns 0. Every token is a valid int and the sum fits long long.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`sumNumbers("8 4 6")` returns `18`; `sumNumbers("")` returns `0`.

<details>
<summary>Small steps / hint</summary>

Use while (input >> number). Add only inside the loop. Do not use while (!input.eof()), which can reuse the previous number after a failed read.

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
