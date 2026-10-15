# Count Matching Numbers

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
3. at(index): return a writable reference to that element. If index < 0 or index >= length, throw std::out_of_range("Invalid index").
4. count(value): return how many elements equal value, not their sum. An empty array returns 0.

Assume n >= 0. int& is provided so a.at(0) = 5 can change the actual element.

Use the supplied fields. No vectors, resizing, copying or extra fields are needed. Functions should not print; main.cpp handles the output. Change only solution.cpp.

## Example

```cpp
NumberArray a(4);
a.at(0) = 5;
a.at(2) = 5;
std::cout << a.count(5) << "\n";
std::cout << a.count(0) << "\n";
std::cout << a.count(9) << "\n";
```

Expected output:
```text
2
2
0
```

main.cpp runs this example and additional checks. Once correct, its last line is `All checks passed!`. The starter compiles but reports `Not finished: Not implemented`. Replace the placeholder throws as you implement each function (keep the required out_of_range exception in 01C).

## Small steps

Write the constructor first, then the destructor, then the other methods. Remove `(void)n;` when you start using n; it only suppresses a starter warning. The other `(void)` lines serve the same purpose.

<details>
<summary>Hint if you get stuck</summary>

For at(), valid indices go from 0 to length - 1. Return data[index], not its address. For count(), add 1 to a counter only when an element equals value.

</details>

## Build and run

Open solution.cpp and use your configured C++ play button, which compiles main.cpp and solution.cpp together. Or, in this exercise folder:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

Do not commit the generated .exe file.
