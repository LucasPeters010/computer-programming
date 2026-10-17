#include "exercise.hpp"

BST::BST(const BST& other) : root(nullptr) {
    root = clone(other.root);
}
BST::Node* BST::clone(const Node* source) {
    // Remove this starter placeholder when you fill the two TODO lines below.
    throw std::logic_error("Not implemented");
    if (source == nullptr) return nullptr;
    Node* copy = new Node(source->key, source->value);
    // TODO START: connect independent copies of BOTH source subtrees.
    // Write two assignments using recursive calls here.
    // TODO END
    return copy;
}
