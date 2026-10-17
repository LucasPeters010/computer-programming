#include "exercise.hpp"

BST::BST(const BST& other) : root(nullptr) {
    root = clone(other.root); // Supplied: focus on the helper.
}
BST::Node* BST::clone(const Node* source) {
    // Every right pointer is nullptr. A left chain may have any length.
    // TODO: empty case, create one node, recursively copy its LEFT subtree,
    // then return the address of the node you created in this call.
    throw std::logic_error("Not implemented");
}
