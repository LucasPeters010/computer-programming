# Build a Price Label

**Easy | Part A, exercise 3 | ZyBook 9.4**

## Goal and exact requirements

Use an ostringstream to return name + ": " + price with exactly two digits after the decimal point. No newline. Name may be empty or contain spaces; price is finite and nonnegative.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`priceLabel("Book", 4.5)` returns `"Book: 4.50"`.

<details>
<summary>Small steps / hint</summary>

Write into output with <<. Use std::fixed and std::setprecision(2). Return output.str(), not output itself.

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
