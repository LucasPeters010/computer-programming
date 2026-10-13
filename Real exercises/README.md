# Real exercises — Computer Programming

36 original practice assignments calibrated against the CP Library's Stack,
MyVector, custom-exception, BST and maze assignments. The earlier Chapter 14
exercises remain separate. These tasks emphasize implementing a specification,
choosing representations and handling edge cases rather than following tiny TODOs.

## Structure

| Category | Exercises |
|---|---|
| [01 - Classes and Interfaces](01%20-%20Classes%20and%20Interfaces/README.md) | 1 easy + 2 medium + 1 hard |
| [02 - Exceptions and Input Validation](02%20-%20Exceptions%20and%20Input%20Validation/README.md) | 1 easy + 2 medium + 1 hard |
| [03 - Streams and Formatting](03%20-%20Streams%20and%20Formatting/README.md) | 1 easy + 2 medium + 1 hard |
| [04 - Dynamic Memory and Resizing](04%20-%20Dynamic%20Memory%20and%20Resizing/README.md) | 1 easy + 2 medium + 1 hard |
| [05 - Linked Lists Stacks and Queues](05%20-%20Linked%20Lists%20Stacks%20and%20Queues/README.md) | 1 easy + 2 medium + 1 hard |
| [06 - Recursion and Backtracking](06%20-%20Recursion%20and%20Backtracking/README.md) | 1 easy + 2 medium + 1 hard |
| [07 - Binary Search Trees](07%20-%20Binary%20Search%20Trees/README.md) | 1 easy + 2 medium + 1 hard |
| [08 - Mixed Exercises](08%20-%20Mixed%20Exercises/README.md) | 3 medium + 3 hard |
| [09 - Final Exam Level](09%20-%20Final%20Exam%20Level/README.md) | 2 final-exam-level tasks |

## How to work

1. Read the README and public interface. Inspect main.cpp for examples.
2. Choose your own private fields and helper functions. Implement in solution.cpp.
3. Compile main.cpp and solution.cpp together from the exercise's folder.
4. Run the public checks, then add the edge cases listed in the README.
5. For owning structures, check memory cleanup as well as printed results.

Every exercise is self-contained. There are no dependencies on previous solutions
and no answer files. Public checks are examples, not hidden grading tests. The
untouched starter compiles but intentionally fails with “Not implemented”.

**Difficulty:** easy means a smaller complete assignment. Medium adds interacting
requirements. Hard approaches the more demanding Library work; the deep-copy
matrix is an explicit extension. Levels are relative to each topic, not a claim
that every easy task is equally difficult. The final tasks are original exam-style
practice, not official exam questions or a guarantee of exam coverage.

**Guidance:** each non-exam task has one collapsed hint. Selected recursion tasks
include high-level pseudocode. You decide the C++ representation and implementation.
No step-by-step pointer recipes are supplied. Public signatures are fixed, private
design is yours. Owning classes disable copying unless copying is the topic.

**Suggested progression:** classes, exceptions, streams, dynamic memory, linked
structures, recursion, BSTs, mixed tasks, then the two final-level exercises.
Do the easy and medium tasks before the hardest tasks if a topic is new.

## Compiling

From any one exercise folder, on Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise.exe
.\exercise.exe
```

On Linux/macOS:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
./exercise
```

The old VS Code active-file build command may compile only one .cpp file. For these
assignments, use the command above so both source files are linked. Add any extra
.cpp files you create to the build command. Do not modify existing VS Code settings
just to open this collection.

After completing a pointer/array exercise, a compiler that supports sanitizers can
help find out-of-bounds access, use-after-free and double deletion:

```bash
g++ -std=c++17 -g -fsanitize=address,undefined -fno-omit-frame-pointer main.cpp solution.cpp -o exercise
./exercise
```

Do not commit generated executables. The local .gitignore excludes common build outputs.

## Source-level calibration

- Library Stack: fixed interface, vector storage, exact toString format, exceptions.
- Library MyVector: logical size versus capacity, resize, bounds and memory ownership.
- Library quadratic/second-smallest tasks: malformed input, standard/custom exceptions.
- Library BST tasks: private dynamic nodes, recursive queries, ordered traversal, cleanup.
- Library maze: cooperating classes and recursive backtracking with algorithm outlines.

The stream section adds focused parsing practice needed by those larger assignments.
Most topic tasks are narrower than the large Library assignments; hard and final
tasks deliberately bring several responsibilities together.
