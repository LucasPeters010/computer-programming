# Quoted Record Parser

**Level: Hard**

Implement a small state-based parser for records containing quoted fields and escaped quotes.

## Requirements

- parseRecord splits one physical line into comma-separated fields. Unquoted fields may contain any characters except comma or double quote. Preserve all spaces.
- A quoted field must start with a double quote as its very first character; commas inside it are ordinary data. Two consecutive double quotes inside a quoted field represent one literal double quote.
- After a closing quote, only comma or end-of-line is allowed. A quote inside an unquoted field, an unclosed quote, or characters after a closing quote throw std::runtime_error("Malformed record"). Embedded newlines are outside scope.
- Empty line is one empty field. Consecutive commas and a final comma create empty fields.
- writeRecord writes fields separated by commas, quoting any field that contains comma or quote and doubling every quote inside it. Do not add a newline. The supplied field vector always contains at least one field; field strings contain no newline or carriage return.
- Parsing a written record must reconstruct the exact fields.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No regex or CSV libraries. Do not discard whitespace.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty quoted field; final empty field; escaped quote next to closing quote; space before a quote.

<details>
<summary>One hint (open only if needed)</summary>

Write down the parser states and which characters can cause transitions before coding.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
