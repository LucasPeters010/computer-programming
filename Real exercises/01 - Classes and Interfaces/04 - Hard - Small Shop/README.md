# Small Shop

**Level: Hard**

Combine two classes without a command parser or complex reporting.

## Requirements

- Product(id,stock) receives a positive ID and nonnegative stock. sell(quantity) succeeds only for quantity > 0 and quantity <= stock, reducing stock; otherwise return false.
- Shop stores Product objects. add(id,stock) returns false for invalid ID/stock or a duplicate ID. Otherwise store a Product and return true.
- sell(id,quantity) delegates to the matching Product; return false if no product matches. totalStock() sums stock across products.
- Use private fields. No reservations, exception classes, sorting or report formatting.

## Required interface

See `exercise.hpp`. Preserve its public signatures. Class tasks include private fields; add helpers if needed. Free-function tasks need no class. `solution.cpp` contains placeholders for your work. Any supplied infrastructure is identified in the requirements; keep it unchanged.

## Constraints

Use vector<Product>. No raw pointers or maps.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty shop; duplicate ID; sell exact stock; failed sale leaves stock unchanged.

<details>
<summary>One hint (open only if needed)</summary>

Keep the stock-changing rule in Product; Shop handles finding the product.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. A provided function is supporting code, not an additional task. Keep the public checks; add your own. Do not commit executables.
