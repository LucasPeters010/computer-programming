# 00H - Finish a Deep Copy

**Tiny warm-up: one missing allocation statement.**

The normal constructor and destructor are supplied. The copy constructor already
contains the value-copy statement from 00E. You provide only the allocation before it.

Read solution.cpp's comments. Replace its TODO throw with one statement that allocates
one integer for data. Do not allocate an array. Do not change the supplied value-copy line.

Example: original stores 9; create copy(original); set copy to 25.
The original must still store 9. Their addresses must differ.

main.cpp checks zero/negative values, independent changes, copying copies and using
a copy after its original is destroyed. All tests run automatically.

Use the play button or compile main.cpp and solution.cpp together. The starter
reports Not implemented; success prints All checks passed!

Think: why is data = other.data wrong even if the copied number initially looks correct?

Next: 00I, then the original exercise 01.
