# Validated Score List

**Level: Medium**

Combine a small class with standard exceptions.

## Requirements

- ScoreList starts empty. add(score) stores scores 0..100; otherwise throw std::out_of_range("Invalid score") and change nothing.
- average() returns a double average or throws std::runtime_error("No scores") when empty.
- passingCount() counts scores >= 55. No stream parser, weighted grades or report formatting.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: classes + vectors + exceptions.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty collection; invalid score; boundary score 55.

<details>
<summary>One hint (open only if needed)</summary>

Validate before adding to the collection.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
