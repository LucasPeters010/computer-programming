# 00D - Create One New Integer

**Tiny warm-up. Do these before exercise 01: 00A -> 00B -> ... -> 00I.**

## One small goal

Allocate one integer and return its address; the caller handles deletion.

Open `solution.cpp` and read its comments. Replace only the TODO block, including
its placeholder throw. The intended answer is about one or two statements.
Keep the supplied declarations and other code. No extra classes, validation or output needed.
All pointers supplied to these functions are valid; do not add null checks.

## Example

`int* p = makeNumber(9);` gives a pointer whose `*p` is 9. Later the caller uses `delete p;`.

## Pause and think

Why must makeNumber NOT delete the integer it returns?

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
