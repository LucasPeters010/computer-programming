# Train Seat Reservations

**Level: Hard**

Build a reservation model in which a booking may cover several consecutive seats and cancellation restores availability.

## Requirements

- SeatRow contains n seats numbered 0..n-1 (n > 0). reserve(bookingId,count) reserves the leftmost consecutive block of count free seats. Return its start index, or -1 when count <= 0, ID <= 0, the ID already occurs in that row, or no suitable block exists. Never split a booking.
- cancel(id) frees every seat with that ID, returning how many seats were freed. occupied() counts occupied seats. layout() returns IDs separated by single spaces, with 0 for free seats and no trailing space.
- Train contains rowCount rows each with seatsPerRow seats (both > 0). book(id,count) uses the first row with a suitable block and returns its zero-based row index, or -1 on failure. IDs must be unique across the entire train.
- Train cancellation searches all rows and returns the number of freed seats. layout() joins row layouts with newlines, including a final newline.
- Failed booking must leave the whole train unchanged. Train must delegate seat operations to SeatRow.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No raw pointers, arrays, structs, maps or global state. Use vectors and at least the two required classes.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Fragmented rows; full train; ID not found; cancellation followed by larger booking.

<details>
<summary>One hint (open only if needed)</summary>

Total free seats are not enough: a booking needs one consecutive block.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
