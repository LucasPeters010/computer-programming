# Room Booking Core

**Level: Medium**

Practise overlap checks without cancellation or formatted schedules.

## Requirements

- StudyRoom starts with no bookings. Only one class is required; there are no people or customer objects.
- reserve(start,end) stores an interval [start,end) if valid and free, returning true; otherwise return false without changes.
- An interval is valid when 0 <= start < end <= 24. isFree(start,end) returns false for an invalid interval or an overlap with ANY stored booking.
- Touching endpoints are allowed: [9,11) and [11,13) do not overlap. bookedHours() totals all booked durations.
- This is the smaller version of the original room task: no cancel(), name, schedule(), sorting or pairs.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use the two supplied vectors with matching indices; do not introduce std::pair.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty room; overlap with second booking; touching endpoints; invalid interval.

<details>
<summary>One hint (open only if needed)</summary>

A free result can only be decided after checking all bookings. Two intervals overlap if start < otherEnd and otherStart < end.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
