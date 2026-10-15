# Create a Zero Array

**Level: Easy — extra practice after 04 / 01**

Do these in order: **01A -> 01B -> 01C**, then retry the original Owned Score Array.

## What you are practising

A dynamic array is a row of integers whose size is chosen when the object is created.
- `data` stores the address of its first element; `data[i]` accesses element i.
- `length` stores how many elements exist. It is not the last index.
- The constructor creates the array once. The destructor releases it once.

## Your tasks

1. Constructor: store n in length and allocate n integers, all zero.
2. Destructor: release that array.

Only these TWO functions are yours to implement. get() and size() are already supplied. Assume n >= 0 and every get index is valid.

Use the supplied fields. No vectors, resizing, copying or extra fields are needed. Functions should not print; main.cpp handles the output. Change only solution.cpp.

## Example

```cpp
ZeroArray a(4);
std::cout << a.size() << "\n";
std::cout << a.get(0) << " " << a.get(3) << "\n";
```

Expected output:
```text
4
0 0
```

main.cpp runs this example and additional checks. Once correct, its last line is `All checks passed!`. The starter compiles but reports `Not finished: Not implemented`. Replace the placeholder throws as you implement each function (keep the required out_of_range exception in 01C).

## Small steps

Write the constructor first, then the destructor. Remove `(void)n;` when you start using n; it only suppresses a starter warning. The other `(void)` lines serve the same purpose.

<details>
<summary>Hint if you get stuck</summary>

Use length = n, not a fixed number. new int[n]{} creates n zero-initialized integers. Match new[] with delete[].

</details>

## Build and run

Open solution.cpp and use your configured C++ play button, which compiles main.cpp and solution.cpp together. Or, in this exercise folder:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the generated .exe file.
