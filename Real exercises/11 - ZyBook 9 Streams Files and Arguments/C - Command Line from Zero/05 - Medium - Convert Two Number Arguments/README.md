# Convert Two Number Arguments

**Medium | Part C, exercise 5 | ZyBook 9.11**

## Goal and exact requirements

Expect exactly two user arguments, guaranteed to be whole-number text in -1000..1000 when both are supplied. Convert using std::atoi, add, print `Sum: N` with newline and return 0. Wrong count: print `Usage: app.exe first second` with newline and return 1. No malformed-number validation, files, stringstreams or exception classes. atoi is used here to match the supplied 9.11 material; it is not a strict validator.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`.\app.exe 8 4` prints `Sum: 12`, not `84`.

<details>
<summary>Small steps / hint</summary>

Check argc first. argv[1] is already a C string, so std::atoi(argv[1]) works directly. If you first store it in a std::string s, the textbook equivalent is std::atoi(s.c_str()).

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

## Try real command-line arguments

The play button runs automatic tests. To supply arguments yourself:

1. In VS Code, right-click this exercise folder and choose Open in Integrated Terminal.
2. Build the real application mode (the main function is already supplied):

```powershell
g++ -std=c++17 -DEXERCISE_APP main.cpp solution.cpp -o app.exe
```

3. Run the command below. Type it into the TERMINAL before the program starts,
not as input to std::cin. EXERCISE_APP is only a switch choosing the supplied
application main instead of the supplied test main; no need to implement macros.

```powershell
.\app.exe 8 4
.\app.exe -8 8
```

For Linux/macOS use ./app and compile with -o app. After running in PowerShell,
`$LASTEXITCODE` shows the returned code: 0 for success, 1 for a requested error.
The usage text uses app.exe as a fixed label, regardless of the actual executable name.
