# Filtered Linked List

**Level: Medium**

Own a singly linked list and remove matching nodes safely, including consecutive matches.

## Requirements

- IntList starts empty. append(value) adds at the end. removeAll(value) removes all matching nodes and returns the number removed, preserving the relative order of survivors.
- reverse() reverses the links in place. contains(value), size(), and toVector() inspect the list; toVector lists head to tail.
- Each element lives in one dynamically allocated node containing an int and a next pointer. Define the node class privately.
- Destructor deletes every node. No leaks, dangling pointers or double deletions. Copying is disabled.
- reverse and removeAll must not allocate replacement nodes.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No STL container for stored nodes. vector only for toVector result. Use actual link reversal, not swapping payloads.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty list; every node matches; consecutive matches; reversal twice; append after clearing.

<details>
<summary>One hint (open only if needed)</summary>

The head is a link too: removing its target changes where the list begins.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
