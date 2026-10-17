# Validate a Number File

**Medium | Part B, exercise 5 | ZyBook 9.5 / 9.3**

## Goal and exact requirements

Open filename or throw runtime_error("Cannot open"). Read whitespace-separated tokens: each must be exactly one valid int. Reject decimals, trailing letters and overflow with runtime_error("Invalid number"). Return a long long sum; empty files return 0. The sum fits long long. Assume a regular readable text file after opening. No report or command-line arguments yet.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

A file containing `8 -4 6` returns 10. A file containing `8 nope 6` throws Invalid number.

<details>
<summary>Small steps / hint</summary>

Combine B03 file iteration with A04 strict parsing, one token at a time. Checking extraction success matters even if eof() is also true: an overflowing final number is invalid.

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
