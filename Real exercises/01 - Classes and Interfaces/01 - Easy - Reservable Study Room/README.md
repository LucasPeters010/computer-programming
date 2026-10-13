# Reservable Study Room

**Level: Easy**

Implement a room that stores non-overlapping bookings. The challenge is maintaining a valid object state across several operations.

## Requirements

- A room is identified by a name. Hours are integer boundaries in the interval 0..24. Bookings use [start,end), so 10..12 and 12..14 may coexist.
- reserve(start,end) returns false for an invalid interval (start < 0, end > 24, or start >= end) or an overlap; otherwise it stores the booking and returns true.
- cancel(start,end) removes only an exact matching booking and returns whether it existed.
- isFree(start,end) returns false for invalid intervals and otherwise reports whether a booking would fit. It must not change the room.
- bookedHours() returns the total duration. schedule() returns bookings sorted by start time as NAME: [9,11) [13,15), or NAME: empty.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use private state and std::vector; no global state, raw pointers or arrays.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: An empty room; a booking inside another; equal endpoints; cancelling a missing booking.

<details>
<summary>One hint (open only if needed)</summary>

Two intervals overlap when they share time, not merely an endpoint.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
