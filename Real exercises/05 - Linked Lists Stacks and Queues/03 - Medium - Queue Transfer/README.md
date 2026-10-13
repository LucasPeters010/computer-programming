# Queue Transfer

**Level: Medium**

Implement a linked queue that can move a prefix into another queue without copying its nodes.

## Requirements

- LinkedQueue has FIFO push, front and pop; pop returns the removed integer. Empty front/pop throw std::runtime_error("Queue is empty").
- transferTo(other,count) moves the first min(count,size) elements to the BACK of other, preserving their order. Return how many moved.
- Negative count throws std::invalid_argument("Negative count") before any changes. Transferring to the same queue with nonnegative count is a no-op returning zero.
- Transfers must relink existing nodes: no new/delete during transfer and no value copying into replacement nodes.
- Maintain first and last pointers and a stored count. Ordinary push, pop, front and size must be O(1); transfer may traverse the moved prefix.
- Each queue destroys its remaining nodes. Copying is disabled. toVector shows front to back.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use a private node class, raw node pointers and new/delete. No STL storage containers except the returned vector.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty source/destination; zero count; move all; source reuse; self transfer.

<details>
<summary>One hint (open only if needed)</summary>

After transferring all nodes, which queue owns each node and which endpoints must change?

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
