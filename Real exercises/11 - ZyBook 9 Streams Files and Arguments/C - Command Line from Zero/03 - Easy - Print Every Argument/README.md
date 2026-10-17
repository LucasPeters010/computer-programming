# Print Every Argument

**Easy | Part C, exercise 3 | ZyBook 9.11**

## Goal and exact requirements

For every user argument print its index, ": ", and its text, followed by newline. Exclude argv[0]. With no user arguments print nothing. Return 0. Treat numbers as text; no conversions or files.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

`.\app.exe red blue 42` prints:
```text
1: red
2: blue
3: 42
```

<details>
<summary>Small steps / hint</summary>

Loop from index 1 while index < argc. argv[argc] is the null sentinel, not another argument to print.

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
.\app.exe red blue 42
.\app.exe "two words" -5
```

For Linux/macOS use ./app and compile with -o app. After running in PowerShell,
`$LASTEXITCODE` shows the returned code: 0 for success, 1 for a requested error.
The usage text uses app.exe as a fixed label, regardless of the actual executable name.
