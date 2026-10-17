# 10 - Copy Constructors

Start here even if copying is completely new. **8 short exercises: 3 very easy, 4 easy, 1 medium.**
Each exercise asks for only one function; all normal constructors, accessors and destructors are supplied.
This chapter can be done after Chapter 04; its number does not mean you must finish the final exams first.

## Read this first

A copy constructor creates a NEW object from an existing object:

```cpp
Counter original(7);     // normal constructor: starts with a number
Counter copy(original); // copy constructor: starts with an existing Counter
Counter third = original; // also copy construction: third is being created here
// copy = original;     // assignment: copy already exists; NOT this chapter
```

`Counter(const Counter& other)` means:
- `other` is a reference to the existing object, so passing it does not create another copy.
- `const` before Counter stops you changing the source through other.
- The constructor has no return type and no trailing const: it initializes the new object.
- Your constructor can read private fields of other objects of the same class.

For int, string and vector fields, ordinary field copying gives independent values.
For an owning int* field, copying its address would make two objects share one allocation.
That is a shallow copy. Both destructors would try to delete the same memory.
A deep copy allocates separate storage and copies the values into it.
The copy must still work after the original is destroyed, and vice versa.
Never delete the source's memory in a copy constructor.

## Work in this order

| Exercise | Level | New idea |
|---|---|---|
| 01 - Copy One Number | Very easy | Read other.field |
| 02 - Copy Two Coordinates | Very easy | Copy every field |
| 03 - Copy a Named Score | Very easy | Copy a string and a number |
| 04 - Copy One Owned Integer | Easy | Allocate one independent int |
| 05 - Copy Three Owned Numbers | Easy | Allocate an array and copy three values |
| 06 - Copy a Vector of Scores | Easy | std::vector already handles copying |
| 07 - Guided Copy of a Dynamic Array | Easy, guided | Length, loop and empty case |
| 08 - Copy Size and Capacity | Medium | Preserve used size and spare storage |

The first three deliberately practise what compiler-generated copying could already do.
Do not use `= default` to skip the requested practice. In all exercises implement only the copy constructor;
do not replace the provided storage with a different container. Assignment is disabled intentionally.
For practice matching the reference site's style, use explicit types, std:: prefixes and vector.at(i).
Raw dynamic arrays use data[i]; that is fine.

## Automatic checks

Every main.cpp includes examples and relevant edge cases, including copying const objects,
copying copies, independent changes and (for owned memory) surviving destruction of the source.
Failures identify the check; the untouched starter reports Not implemented.
A failed address check exits immediately so an obvious shallow copy does not reach two destructors.
Tests cannot prove absence of all memory bugs; an AddressSanitizer build is useful for finished pointer exercises.
No reference solutions are included.

Use the existing play-button task or compile main.cpp and solution.cpp together from an exercise folder:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

## Difficulty reference

Calibrated against https://goncalo-soares.com/ace-cp/ (accessed 17 October 2026).
That site labels its dynamic-vector copy constructor medium, copy assignment hard,
and BST copy constructor hard. These original exercises provide more stepping stones before that medium task.
Exercise 07 is easier because it includes a step-by-step hint; 08 adds capacity bookkeeping.
No tree copying or assignment is required here.
