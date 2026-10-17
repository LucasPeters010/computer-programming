# Withdrawal or Error

**Level: Medium | Extra practice after 02A**

Choose between a standard exception and your own exception. This is a small
function exercise, not a full bank-account class. All amounts are whole units.

## Requirements

- Implement InsufficientFunds's constructor and getters. Store both arguments
  exactly; use no inheritance or what() method.
- withdraw(balance, amount) assumes **balance >= 0**; no validation for negative balances is required.
- First: amount <= 0 throws std::invalid_argument("Invalid amount").
- Otherwise: amount > balance throws InsufficientFunds carrying **amount as requested**
  and **balance as available**.
- Otherwise return balance - amount. Withdrawing the exact balance is allowed.
- No printing, input parsing, pointers, global state or account object.

## Your tasks

Implement the four supplied functions in solution.cpp. The caller handles exceptions.
Both arguments are passed by value; returning a new balance does not itself update
any variable in the caller.

## Example

```cpp
int balance = 100;
balance = withdraw(balance, 30); // balance becomes 70
try {
    balance = withdraw(balance, 80);
} catch (const InsufficientFunds& error) {
    std::cout << "Requested: " << error.requestedAmount() << '\n';
    std::cout << "Available: " << error.availableAmount() << '\n';
}
// Requested: 80
// Available: 70
// balance remains 70: throwing means the assignment never receives a result.
```

## Automatic edge cases

Zero/negative amounts, empty balance, exact balance, one unit too much, extreme
integer values, both exception payloads and successful use after a caught error.

<details><summary>One hint</summary>

Check invalid amounts before subtracting. The custom exception stores the two
numbers; the function decides whether the request can succeed.

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
