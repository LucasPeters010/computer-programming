# Course Gradebook

**Level: Medium**

Represent weighted assessments and a collection of students using a stable class interface.

## Requirements

- Each student has an integer ID. addGrade(mark,weight) accepts marks 0..10 and positive weights, provided total weight will not exceed 100. Return false without changes otherwise.
- average() is sum(mark * weight) / sum(weight), or 0 if no grades exist. complete() means total weight is 100. passed() means complete and average >= 5.5.
- Gradebook enroll rejects duplicate IDs. record rejects unknown students or invalid grades, returning bool.
- passedIds() returns only IDs of complete, passing students in ascending order. cohortAverage() averages the averages of complete students only; return 0 if none are complete.
- Store each student's actual assessments; do not hard-code a fixed assessment count. Use double marks and integer percentage weights.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use at least these two classes and private state; vectors allowed. No maps or raw pointers.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: No students; no completed students; exactly 5.5; rejected weight leaves previous results unchanged.

<details>
<summary>One hint (open only if needed)</summary>

Incomplete students and failing students are different cases.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
