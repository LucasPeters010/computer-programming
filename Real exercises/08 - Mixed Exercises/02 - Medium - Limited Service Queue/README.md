# Limited Service Queue

**Level: Medium**

Combine an owning linked queue of objects with domain-specific exceptions and formatted output.

## Requirements

- Request has a positive integer ID and nonempty description; its constructor throws std::invalid_argument("Invalid request") otherwise. toString returns #ID DESCRIPTION.
- ServiceQueue(limit) has nonnegative fixed capacity, otherwise throw std::invalid_argument("Negative capacity"). add(id,description) first validates the Request, then rejects an ID already queued with std::runtime_error("Duplicate request"), then a full queue with std::runtime_error("Queue is full").
- serve removes the oldest request and returns its formatted string, throwing std::runtime_error("Queue is empty") when empty.
- cancel(id) removes that request from any queue position and returns bool. Cancelled IDs may be reused. listing returns front-to-back request strings each with newline; empty queue gives empty string.
- size inspects the count. Nodes contain Request objects. Destructor frees all nodes; copying is disabled.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Private dynamic node class; no STL storage containers. Focus: classes + linked queue + exceptions.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Capacity zero; invalid request when full; duplicate when full; cancel sole request; add after tail removal.

<details>
<summary>One hint (open only if needed)</summary>

Cancellation must preserve the same endpoint invariants as ordinary queue removal.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
