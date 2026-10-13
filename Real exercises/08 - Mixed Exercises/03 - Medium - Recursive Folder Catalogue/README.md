# Recursive Folder Catalogue

**Level: Medium**

Combine class modelling, recursive queries and hierarchical text formatting without pointers.

## Requirements

- Catalogue starts with a root folder named root (ID 0). addFolder(parentId,name) creates a child and returns a sequential ID starting at 1. Unknown parent throws std::out_of_range("Unknown folder"). Folder names are nonempty, single tokens and unique among that parent's child folders; invalid/duplicate names throw std::invalid_argument("Invalid folder name").
- addFile(folderId,name,bytes) adds a file. Unknown folder uses the same error; empty/multiword file name, negative bytes, or duplicate file name in that folder throws std::invalid_argument("Invalid file"). A file and folder may share a name.
- totalBytes(folderId) recursively sums that folder's files and all descendants, returning long long. Unknown folder uses the same error.
- outline(folderId) prints the folder name followed by / and newline. Then print its files in insertion order as NAME BYTES, followed by its child folders recursively in insertion order. Indent each level by two spaces. Always end with newline.
- Use a private Folder class. A vector may store folders by ID; child relationships can be IDs. No removal is needed.

## Required interface

See `exercise.hpp`. Preserve its public signatures and add your own private data and helper functions. `solution.cpp` contains deliberately unimplemented method bodies, not a worked solution.

## Constraints

No raw pointers, arrays, structs or maps. Recursive helpers required for totals and outline. Focus: classes + recursion + formatting.

## Examples and checks

`main.cpp` contains executable examples, expected values/output and selected failure cases. Read these alongside the requirements. Passing them is not proof that every edge case is handled.

Additional cases to test: Empty folders; deeply nested folders; duplicate sibling name versus same name under different parents; zero-byte files.

<details>
<summary>One hint (open only if needed)</summary>

Separate folder identity from its position in a recursive traversal.

</details>

## Build and run

From this exercise folder:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise
```

Run `./exercise` on Linux/macOS, or `.\exercise.exe` in Windows PowerShell (use `-o exercise.exe` when compiling there). Compile both .cpp files together; do not compile exercise.hpp as a standalone program.

The untouched starter builds, then reports **Not finished: Not implemented**. Replace the placeholder throws as you implement. Unused-parameter warnings are expected in untouched stubs. Keep the public checks; add your own. Do not commit executables.
