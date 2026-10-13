# Run Length Archive

**Level: Medium**

Encode text and decode a strict textual archive format without losing spaces or newline characters.

## Requirements

- encodeRuns reads bytes from an istream, including whitespace, and writes one line per maximal run: COUNT:CODE followed by newline. CODE is the unsigned byte value 0..255; count is positive. Treat char values as unsigned when producing codes.
- decodeRuns reads this format and writes the reconstructed bytes. Each line must contain exactly one colon and two nonempty decimal digit sequences; no spaces, signs or extra characters. Count must be 1..1000 and code 0..255. A blank line is invalid.
- Decoder throws std::runtime_error("Invalid archive") for invalid syntax/ranges, including numbers too large to parse. Decode the whole archive successfully before writing anything to output.
- Empty input encodes/decodes to empty output. For encoding, assume each original run is at most 1000 bytes. The decoder need not reject adjacent entries with the same code.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

Use standard streams and strings; no regex or external compression libraries.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: One byte; no final newline in archive; leading zeros (allowed); huge count token; invalid final entry.

<details>
<summary>One hint (open only if needed)</summary>

Formatted extraction skips whitespace; decide which operations must preserve every byte.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
