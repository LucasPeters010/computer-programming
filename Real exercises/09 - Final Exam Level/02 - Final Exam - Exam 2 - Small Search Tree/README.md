# Exam 2 - Small Search Tree

**Level: Final Exam**

Build a BST and add a concise recursive summary.

Suggested practice time: **90 minutes**. This is an original practice task, not an official VU exam or a prediction of its exact scope.

## Requirements

- ExamTree starts empty. Each inserted distinct integer gets one dynamic node; duplicates are ignored. Implement insert, contains, inOrder, height and destructor. Empty height is zero and singleton height is one.
- treeSummary(input,output) reads valid whitespace-separated ints to EOF. Print ascending distinct keys separated by single spaces and newline, then Height: H and newline.
- Use recursive helpers for inOrder, height and cleanup. Insertion and search may be iterative or recursive.
- Node representation and root pointer are supplied. No balancing, deletion, range queries, malformed-input handling or command parser. Copying disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Raw BST nodes required. vector only for traversal output. 90-minute original exam-style practice, not an official exam.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty tree; duplicate keys; skewed tree; single node; destructor after multiple inserts.

## Self-marking rubric (100 points)

- Node ownership and cleanup: 20 points
- Insertion and search: 30 points
- Recursive traversal and height: 30 points
- Stream summary and edge cases: 20 points

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
