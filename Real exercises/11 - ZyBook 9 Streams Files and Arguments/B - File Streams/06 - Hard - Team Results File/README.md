# Team Results File

**Hard | Part B, exercise 6 | ZyBook 9.5 / 9.7**

## Goal and exact requirements

Read records from a file. A record is a nonempty team-name line (may contain spaces), followed by ONE statistics line.
The statistics line contains one integer (wins, losses default 0) or two integers (wins and losses), each 0..1000.
Allow surrounding whitespace, reject extra tokens, decimals, overflow and blank statistics.
Print `NAME: W wins, L losses` or `NAME: Invalid`, each with newline.
Always consume the statistics line even when invalid, then continue with the next name.
A name at EOF with no statistics line prints Invalid. Empty file prints nothing.
Opening failure throws runtime_error("Cannot open"). Team-name lines are guaranteed nonempty.
This is a fixed two-line format inspired by 9.7, not a reproduction of its optional-line format.

Implement only the function in solution.cpp. Keep supplied code and signatures.
No hard-coded test answers, no changes to main.cpp, no unrelated classes or algorithms.
Output only the text requested below; no debug messages.

## Example

File:
```text
Red Team
5 2
Blue Team
3
```
Output:
```text
Red Team: 5 wins, 2 losses
Blue Team: 3 wins, 0 losses
```

<details>
<summary>Small steps / hint</summary>

Use getline for name and statistics separately. Parse only the statistics string with istringstream. An optional missing second number is different from an invalid second number.

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
