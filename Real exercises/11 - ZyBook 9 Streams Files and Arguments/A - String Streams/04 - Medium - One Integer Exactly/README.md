# One Integer Exactly

**Medium | Part A, exercise 4 | ZyBook 9.3 / 9.5**

## Goal and exact requirements

Return true only for exactly one int with optional surrounding whitespace. On success assign it to value. On failure return false and leave value unchanged. Reject decimals, extra tokens, nonnumeric input and integer overflow. Do not throw for bad input.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

With value initially 91: `parseInteger(" 12 ", value)` gives true and 12; `parseInteger("12abc", value)` gives false without changing value.

<details>
<summary>Small steps / hint</summary>

First check extraction into a temporary. Then skip whitespace with std::ws and check for leftover characters. Assign to value only after all checks pass.

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
