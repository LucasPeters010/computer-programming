# Booking Command Session

**Level: Hard**

Combine basic booking logic with a three-command parser.

## Requirements

- BookingDesk starts empty. book(start,end) returns false for invalid hours or overlap, otherwise stores the booking and returns true. Valid intervals satisfy 0 <= start < end <= 24; touching endpoints are allowed.
- hours() sums durations. No cancellation or schedule output.
- runBookings reads physical lines: BOOK start end, HOURS, or CLEAR. A successful BOOK prints Booked, rejected interval/overlap prints Unavailable, HOURS prints the total, CLEAR resets the desk silently. Each output ends with newline.
- Malformed lines (including extra tokens) print Invalid command and leave state unchanged. Continue after errors. Implement CLEAR by assigning a fresh BookingDesk; it owns vectors, not raw pointers.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Focus: classes + vectors + streams. Two vectors of hours are sufficient; no pairs.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Run main.cpp normally to include the edge cases; no manual additions are needed. These checks exercise behaviour, but cannot prove that an implementation uses recursion or releases all memory correctly.

Cases now checked automatically in main.cpp: Overlap with later booking; invalid hours; malformed BOOK; HOURS after CLEAR.

<details>
<summary>One hint (open only if needed)</summary>

Parse each command completely before calling the class method.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. The supplied main.cpp runs the examples and additional edge-case checks automatically. Do not commit executables.
