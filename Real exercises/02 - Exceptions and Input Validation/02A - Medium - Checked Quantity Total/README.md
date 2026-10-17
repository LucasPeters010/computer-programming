# Checked Quantity Total

**Level: Medium | Extra practice after 02 - Average or Error**

Practise throwing your own exception object. This time it carries both the
position AND the bad value, so a catch can explain exactly what happened.

## Requirements

- Implement InvalidQuantity's constructor and two getters. Store the arguments
  exactly. This is an ordinary class; do not add inheritance or a what() method.
- checkedTotal accepts quantities from **0 through 1000 inclusive** and returns their sum as long long.
- Empty input throws std::runtime_error("No quantities").
- Otherwise inspect entries from left to right. The first invalid quantity must
  throw InvalidQuantity containing its zero-based index and its value.
- Leave the vector unchanged. Do not print from these functions.
- All int input values are allowed; invalid ones must be reported, not clamped.
  Assume the vector length fits in int.

## Your tasks

Implement only the four supplied functions in solution.cpp. No stream parsing,
extra classes or try/catch inside checkedTotal are required; main.cpp catches errors.

## Example

```cpp
std::cout << checkedTotal({4, 0, 12}) << '\n'; // 16
try {
    checkedTotal({4, -2, 7});
} catch (const InvalidQuantity& error) {
    std::cout << error.position() << ": " << error.value() << '\n';
}
// Prints: 1: -2
```

## Automatic edge cases

Empty input, zero, 1000, negatives, 1001, extreme integers, bad entries at the
first/middle/last position, several bad entries, payload getters and unchanged input.

<details><summary>One hint</summary>

A throw can construct an object with two arguments. Its constructor should only
store them; the checking function decides when to throw it.

</details>

## Build and run

Open solution.cpp and use the configured C++ play button, or run from this folder:

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o solution.exe
.\solution.exe
```

The starter compiles and reports `Not finished: Not implemented`. Replace the
placeholder throws in solution.cpp; do not replace the tests. main.cpp automatically
runs the example and edge cases. Success prints `All example and edge-case checks passed.`
No manual test additions are needed. Do not commit executables.
