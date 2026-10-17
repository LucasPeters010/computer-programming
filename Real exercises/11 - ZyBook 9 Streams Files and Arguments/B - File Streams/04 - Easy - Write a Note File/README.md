# Write a Note File

**Easy | Part B, exercise 4 | ZyBook 9.8**

## Goal and exact requirements

Open filename with ofstream, replacing any old contents. Write text followed by exactly one newline. If opening fails, throw runtime_error("Cannot write"). Text contains no newline characters and may be empty. Assume writing succeeds after opening; close the stream before returning.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`writeNote("note.txt", "Hello Lucas")` creates a file containing `Hello Lucas` and a newline.

<details>
<summary>Small steps / hint</summary>

Open, check is_open(), write with <<, close. Do not write to cout instead of the file.

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
