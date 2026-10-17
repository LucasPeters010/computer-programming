# 08 - Medium - Copy a Branching Tree

**New step:** Combine two recursive results under a new parent.

## Your task

The tree can now branch and have any depth. Only fill the two missing child assignments. The base case, parent allocation and return are supplied. Keep the same shape, even when only one child exists.

Edit only the requested functions in `solution.cpp`. In exercise 09 you may also add private helper declarations in `exercise.hpp`. Remove the placeholder throw when implementing a TODO. Assume allocations succeed; allocation-failure recovery is outside this practice, as on the reference page.

## Which name means what?

| Expression | Meaning |
|---|---|
| `BST` | Type of the whole tree object |
| `Node` / `BST::Node` | One nested class type; not an automatic node object |
| `root` | This tree object's pointer to its first node |
| `other` | The existing BST object in a copy constructor |
| `other.root` | The source tree's first-node address |
| `source` or `node` in a helper | One node address, not a whole BST object |
| `node->left` | A pointer stored in that node; nullptr or a child's address |

The two pointer fields do not contain whole child objects. New child nodes are separate allocations. Defining `class Node` inside `class BST` organizes the type's name; it does not create any nodes.

## Check your work

Run `main.cpp` or `solution.cpp` with your existing play-button setup. It builds both files. The untouched starter builds and reports `Not implemented`; completed work prints `All checks passed.`

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp solution.cpp -o exercise.exe
.\exercise.exe
```

The provided tests check the stated shapes and missing-node cases. Copy tasks check every node address, both directions of mutation, const sources, copies of copies, and destruction in either order. They stop immediately on failed ownership checks. They do not replace a memory sanitizer for arbitrary invalid pointer code.

<details>
<summary>Small hint (optional)</summary>

Each side uses the same helper, with a different source pointer and a different destination pointer.

</details>
