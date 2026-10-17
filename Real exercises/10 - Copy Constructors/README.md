# 10 - Copy Constructors

Start with **9 tiny warm-ups (00A-00I)**, then the original **8 exercises: 3 very easy, 4 easy, 1 medium.**
The warm-ups usually ask for one or two statements, with explanations beside the TODO.
The original exercises 01-08 each ask for one copy constructor; other infrastructure is supplied.
This chapter can be done after Chapter 04; its number does not mean you must finish the final exams first.

## Start with the tiny warm-ups

Do these in order before exercise 01. Each has its own README, exercise.hpp, solution.cpp and automatic main.cpp tests.

| Warm-up | One small step |
|---|---|
| 00A - Read Through a Pointer | Read the number at an address |
| 00B - Change Through a Pointer | Write to the number at an address |
| 00C - Share an Address Safely | Observe two pointers reaching one integer, without deleting it |
| 00D - Create One New Integer | Allocate independent storage |
| 00E - Copy a Number Not an Address | Copy into storage that already exists |
| 00F - Read the Other Objects Field | Complete one line of a scalar copy constructor |
| 00G - Pass an Object by Value | Change a local copy without changing the original |
| 00H - Finish a Deep Copy | Add an allocation before the supplied value-copy line |
| 00I - Watch Each Owner Be Destroyed | Complete delete and watch the lifetime trace |

Only change the marked TODO block. The throw is a starter placeholder, not part of your solution.
Warm-up 00I temporarily declares its destructor noexcept(false) so the placeholder exception can
produce a friendly message; keep the declaration supplied, and replace the throw with deletion.
Normal destructors should not throw. The live counter illustrates lifetime; it is not a memory-leak detector.

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
Do not use `= default` to skip the requested practice. In exercises 01-08 implement only the copy constructor;
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
