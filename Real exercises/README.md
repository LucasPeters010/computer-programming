# Real exercises — revised difficulty

56 exercises, including extra dynamic-array practice and a new beginner-friendly copy-constructor chapter.
The original seven topics use an easy/medium/hard progression; mixed tasks and final-exam practice follow.

The original full room-booking task was too large for an easy exercise. It is a
medium+ reference point for this collection. Most revised easy tasks have one main
goal and a short interface. Medium adds one complication; hard combines a few
related responsibilities. Difficulty is relative to the topic: new tree concepts
can still need explanation even with a short implementation.

The smaller Room Booking Core task keeps overlap checks and totals but removes
cancellation, sorting, names and schedule formatting. The rest of the collection
has been reduced in the same way, not merely relabelled.

## Categories

| Folder | Exercises |
|---|---|
| [01 - Classes and Interfaces](01%20-%20Classes%20and%20Interfaces/README.md) | 1 easy, 2 medium, 1 hard |
| [02 - Exceptions and Input Validation](02%20-%20Exceptions%20and%20Input%20Validation/README.md) | 1 easy, 2 medium, 1 hard |
| [03 - Streams and Formatting](03%20-%20Streams%20and%20Formatting/README.md) | 1 easy, 2 medium, 1 hard |
| [04 - Dynamic Memory and Resizing](04%20-%20Dynamic%20Memory%20and%20Resizing/README.md) | 4 easy, 2 medium, 1 hard |
| [05 - Linked Lists Stacks and Queues](05%20-%20Linked%20Lists%20Stacks%20and%20Queues/README.md) | 1 easy, 2 medium, 1 hard |
| [06 - Recursion and Backtracking](06%20-%20Recursion%20and%20Backtracking/README.md) | 1 easy, 2 medium, 1 hard |
| [07 - Binary Search Trees](07%20-%20Binary%20Search%20Trees/README.md) | 1 easy, 2 medium, 1 hard |
| [08 - Mixed Exercises](08%20-%20Mixed%20Exercises/README.md) | 3 medium, 3 hard |
| [09 - Final Exam Level](09%20-%20Final%20Exam%20Level/README.md) | 2 exam-style tasks |
| [10 - Copy Constructors](10%20-%20Copy%20Constructors/README.md) | 9 tiny warm-ups, 3 very easy, 4 easy, 1 medium |

## What is provided

- Clear requirements and a small public interface, with private fields for class tasks.
- Runnable public examples in main.cpp; implement the missing bodies in solution.cpp.
- One optional hint per non-exam task, and short pseudocode where appropriate.
- Working tree infrastructure in the first three tree tasks and the mixed tree report.
- Outside the dedicated copy-constructor chapter, no required deep-copy machinery.
  No required pairs, maps, matrix resizing, atomic batch imports,
  complex CSV parsing, tree deletion or ownership-transfer operations.

Use only the methods requested. No extra customer classes, interfaces or features
are needed. Do not add validation for inputs explicitly guaranteed valid. The
untouched starter builds but reports Not implemented; supplied infrastructure may
already work. Public checks include automatic edge cases in Chapters 07-10; they are not an exhaustive grading suite.

The final tasks are **90-minute original exam-style practice**, not official exam
questions or a guarantee of exam scope. They combine core skills, without the
advanced extras from the first version.

## Build

From the individual exercise folder on Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise.exe
.\exercise.exe
```

On Linux/macOS use `-o exercise` and run `./exercise`. Compile BOTH .cpp files.
Unused-parameter warnings in placeholder functions are expected. Complete the
public checks, then try the additional cases listed in the README. Do not commit
executables. For completed memory exercises, an AddressSanitizer-capable compiler
can check memory errors using `-g -fsanitize=address,undefined`.

## Calibration

These are smaller practice tasks based on the Library's class interfaces, Stack,
MyVector, exceptions, recursive BST queries and maze backtracking. The first
version is retained in Git history; the separate Chapter 14 folder is unchanged.
