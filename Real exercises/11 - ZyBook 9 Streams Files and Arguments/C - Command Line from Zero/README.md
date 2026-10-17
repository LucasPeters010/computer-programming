# C - Command Line from Zero

This part starts from ZERO. It is independent of A and B: no file opening,
stringstreams, custom exceptions, trees or dynamic-memory exercises.

## Before the first exercise

A command-line argument is text you type AFTER the executable name when starting a program:

```powershell
.\app.exe Lucas 18
```

This is not an answer to a cin prompt. The values are already available when main starts.
The operating system calls a main with this signature:

```cpp
int main(int argc, char* argv[])
```

| Expression | Value for the example |
|---|---|
| argc | 3 (program name + two user values) |
| argv[0] | executable name/path, such as .\app.exe |
| argv[1] | text "Lucas" |
| argv[2] | text "18", NOT integer 18 |
| argv[3] | nullptr sentinel: do not read it as a string |

argv is a raw array of C-string pointers, NOT std::vector. argv[i] is appropriate.
You can print argv[i] or copy it into std::string. No pointer allocation is needed.
For these exercises argc is at least 1. Never access argv[1] until argc proves it exists.

Quotes keep spaces inside ONE argument:

```powershell
.\app.exe "Lucas Peters" 18
```

Here argc is still 3. Without quotes, Lucas and Peters are separate arguments.

## Why you implement run instead of main

main.cpp already forwards real argc and argv to your run function, plus an output
stream. This lets the same code be tested automatically. Treat run's argc/argv as
main's parameters. Write requested output to output, not directly to cout.
The supplied forwarding code passes cout in real application mode.
The const qualifiers prevent changing the argument text or pointers; reading works normally.
A return value of 0 means success; 1 means a handled error such as wrong argument count.
Returning 1 in a usage case is intentional, not a compiler failure.

## Two ways to run

The existing play button builds main.cpp + solution.cpp and runs automatic tests,
including simulations of no arguments and quoted arguments. No task configuration changes needed.
To actually type your own command-line arguments, follow each exercise's three
PowerShell steps: open its terminal, build with -DEXERCISE_APP, then run app.exe.
You can start C01 directly even if A/B are unfinished.

| Exercise | Level | ZyBook |
|---|---|---|
| [01 - Count User Arguments](01%20-%20Very%20Easy%20-%20Count%20User%20Arguments/README.md) | Very Easy | 9.11 |
| [02 - Read Your First Argument](02%20-%20Very%20Easy%20-%20Read%20Your%20First%20Argument/README.md) | Very Easy | 9.11 |
| [03 - Print Every Argument](03%20-%20Easy%20-%20Print%20Every%20Argument/README.md) | Easy | 9.11 |
| [04 - Check Two Arguments](04%20-%20Easy%20-%20Check%20Two%20Arguments/README.md) | Easy | 9.11 |
| [05 - Convert Two Number Arguments](05%20-%20Medium%20-%20Convert%20Two%20Number%20Arguments/README.md) | Medium | 9.11 |
