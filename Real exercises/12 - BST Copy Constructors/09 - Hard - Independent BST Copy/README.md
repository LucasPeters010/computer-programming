# 09 - Hard - Independent BST Copy

**New step:** Website-level task with no algorithm supplied.

## Your task

Implement the copy constructor and any private helpers you choose. Match the linked website's target: arbitrary BST, int keys, string values, same shape, separate nodes, independent insertion/update, empty trees and safe destruction. Do not change public interfaces or supplied infrastructure. Copy assignment is disabled. Do not flatten/reinsert or use a container as replacement storage; practise copying the existing structure.

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

No step-by-step hint here. If stuck, revisit exercise 08, then close it and try this fresh.

</details>
