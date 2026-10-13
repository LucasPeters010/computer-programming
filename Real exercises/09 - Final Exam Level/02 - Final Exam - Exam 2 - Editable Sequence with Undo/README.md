# Exam 2 - Editable Sequence with Undo

**Level: Final Exam**

Implement a dynamic sequence editor with one-step undo and an atomic batch operation.

Suggested practice time: **120 minutes**. This is an original practice task, not an official VU exam or a prediction of its exact scope.

## Requirements

- SequenceEditor starts empty. Store the current integers in your own dynamic array. at(index) checks 0 <= index < size and throws std::out_of_range("Index out of range").
- insert(index,value) accepts 0 <= index <= size; erase(index) accepts 0 <= index < size and returns the removed value; invalid indices use the same error. resize(n) preserves the first min(oldSize,n) values and zero-initializes growth; negative n throws std::invalid_argument("Negative size"). Choose any sensible capacity policy.
- Every successful insert, erase, resize, or batch operation saves the previous sequence as the ONLY undo snapshot. Even a successful no-op resize replaces the snapshot. Failed operations preserve both current contents and the existing snapshot.
- undo() restores the snapshot and consumes it. With no snapshot, throw std::runtime_error("Nothing to undo"). hasUndo() reports availability; toString returns [a,b,c], or [].
- applyBatch(input) accepts lines INSERT index value, ERASE index, RESIZE size with exact integer arguments and no extra tokens. Grammar failure throws std::runtime_error("Invalid command"); domain errors are those above. Validate/process lines in order and stop at the first failure.
- A batch is ONE atomic edit: either all lines apply and one snapshot holds the state from before the entire batch, or the complete current state and previous undo snapshot stay unchanged. Empty input is a successful no-op edit that still replaces the snapshot. Blank lines are invalid.
- Destructor frees current storage and any snapshot/temporary storage. Copying is disabled. No public method may leak memory after a rejected batch. No redo is required.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Current values, undo snapshot and working sequences must use raw dynamic arrays. No STL containers for integer storage or command buffering. String streams are allowed.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Undo empty state; failed edit with existing snapshot; empty batch; bad final batch line; repeated resize; reuse after undo.

## Self-marking rubric (100 points)

- Array ownership, growth and indexing: **25 points**
- Insert, erase and resize: **20 points**
- One-step undo semantics: **20 points**
- Atomic batch parsing and rollback: **25 points**
- Cleanup and failure cases: **10 points**

Score against the full requirements, not only the public checks. Complete it once without hints, then review failed cases.

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
