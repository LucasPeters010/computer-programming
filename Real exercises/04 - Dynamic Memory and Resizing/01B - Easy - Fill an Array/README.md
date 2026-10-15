# Fill an Array

**Level: Easy — extra practice after 04 / 01**

Do these in order: **01A -> 01B -> 01C**, then retry the original Owned Score Array.

## What you are practising

A dynamic array is a row of integers whose size is chosen when the object is created.
- `data` stores the address of its first element; `data[i]` accesses element i.
- `length` stores how many elements exist. It is not the last index.
- The constructor creates the array once. The destructor releases it once.

## Your tasks

1. Constructor: store n and allocate n zero-initialized integers.
2. Destructor: release the array.
3. fill(value): change EVERY element to value using a loop.

Assume n >= 0 and every get index is valid. get() is supplied. Calling fill on an empty array does nothing.

Use the supplied fields. No vectors, resizing, copying or extra fields are needed. Functions should not print; main.cpp handles the output. Change only solution.cpp.

## Example

```cpp
FillArray a(3);
a.fill(7);
std::cout << a.get(0) << " " << a.get(1) << " " << a.get(2) << "\n";
a.fill(-2);
std::cout << a.get(0) << "\n";
```

Expected output:
```text
7 7 7
-2
```

main.cpp runs this example and additional checks. Once correct, its last line is `All checks passed!`. The starter compiles but reports `Not finished: Not implemented`. Replace the placeholder throws as you implement each function (keep the required out_of_range exception in 01C).

## Small steps

Write the constructor first, then the destructor, then the other methods. Remove `(void)n;` when you start using n; it only suppresses a starter warning. The other `(void)` lines serve the same purpose.

<details>
<summary>Hint if you get stuck</summary>

Reuse what you learned in 01A. In fill(), loop from index 0 while index < length. Assign to data[index]; the array already exists.

</details>

## Build and run

Open solution.cpp and use your configured C++ play button, which compiles main.cpp and solution.cpp together. Or, in this exercise folder:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the generated .exe file.
