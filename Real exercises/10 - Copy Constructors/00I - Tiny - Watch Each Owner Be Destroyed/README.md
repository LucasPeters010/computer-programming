# 00I - Watch Each Owner Be Destroyed

**Tiny warm-up. Do these before exercise 01: 00A -> 00B -> ... -> 00I.**

## One small goal

Release one owned integer in the destructor, then watch a supplied deep copy keep the original alive after a by-value call.

Open `solution.cpp` and read its comments. Replace only the TODO block, including
its placeholder throw. The intended answer is about one or two statements.
Keep the supplied declarations and other code. No extra classes, validation or output needed.
All pointers supplied to these functions are valid; do not add null checks.

## Example

The trace shows: original created -> local copy changed to 25 -> local destroyed -> original still 9 -> original destroyed.
A preliminary test object prints one destructor line first.

## Pause and think

Why does deleting the local copy no longer invalidate the original?

## Automatic checks and running

`main.cpp` already checks the example and relevant edge cases. Read its comments
to follow the object's lifetime. You do not have to write any tests.
An untouched starter compiles, then prints `Not finished: Not implemented`.
A completed exercise prints `All checks passed!` (00I also prints a lifetime trace).

Use the configured play button with this folder's solution.cpp open, or run:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the executable. After 00I, go to `01 - Very Easy - Copy One Number`.
