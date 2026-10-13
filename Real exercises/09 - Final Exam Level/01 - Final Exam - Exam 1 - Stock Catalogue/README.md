# Exam 1 - Stock Catalogue

**Level: Final Exam**

Implement a complete small stock-management program using an owning BST and a stream command interface.

Suggested practice time: **120 minutes**. This is an original practice task, not an official VU exam or a prediction of its exact scope.

## Requirements

- StockTree stores unique positive product IDs with nonnegative integer stock in unbalanced dynamic BST nodes. add(id,quantity) inserts a new product or increases an existing stock. Invalid id or negative quantity throws std::invalid_argument("Invalid product"). Zero quantity is allowed. Assume arithmetic fits int.
- sell(id,quantity) requires positive quantity or throws std::invalid_argument("Invalid quantity"); then an unknown ID throws std::out_of_range("Unknown product"); then insufficient stock throws std::runtime_error("Insufficient stock"). Leave the product present when stock reaches zero.
- stock(id) returns the stock, throwing "Unknown product" when missing. totalStock() recursively returns the sum as long long. lowStock(limit) returns ascending IDs with stock strictly below limit; a negative limit returns empty.
- write(output) prints ascending ID order, one ID STOCK line per product. Destructor frees all nodes; copying is disabled.
- runStockSession accepts one command per physical line: ADD id quantity, SELL id quantity, GET id, LOW limit, TOTAL, LIST. Each numeric argument must be an int and no extra tokens are allowed. Blank/unknown/malformed commands print ERROR: Invalid command and newline.
- ADD/SELL succeed silently. GET/TOTAL print the number and newline. LOW prints ascending IDs separated by single spaces, or none, followed by newline. LIST uses write(). Domain errors print ERROR: MESSAGE and newline. Continue after every rejected line. Parse the full line before changing the tree.
- Do not delete products or balance the tree. Use the required interface and choose your own node representation and helpers.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Raw dynamic BST nodes required. No maps or containers for tree storage; vector allowed only for returned ID collections. Recursion required for summaries and ordered output.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty catalogue; duplicate ID update; zero stock; invalid command must not insert a product; errors followed by valid commands.

## Self-marking rubric (100 points)

- BST storage, insertion and lookup: **25 points**
- Stock updates and exception guarantees: **20 points**
- Recursive queries and sorted output: **20 points**
- Strict parsing and recovery: **25 points**
- Memory cleanup and edge cases: **10 points**

Score against the full requirements, not only the public checks. Complete it once without hints, then review failed cases.

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
