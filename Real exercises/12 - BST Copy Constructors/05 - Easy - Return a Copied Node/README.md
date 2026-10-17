# 05 - Easy - Return a Copied Node

**New step:** Translate a private nested return type and wire the helper.

## Your task

The input tree again has at most one node so you can focus only on moving the work into a helper. Implement `cloneLeaf` and the one-line constructor connection. Return a pointer to the new node, not a pointer to a local stack variable.

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

The helper receives one node address. The constructor receives the whole source object. Ask: which member of that object contains the starting node address?

</details>
