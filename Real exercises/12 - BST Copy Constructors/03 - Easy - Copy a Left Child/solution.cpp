#include "exercise.hpp"

BST::BST(const BST& other) : root(nullptr) {
    // Source is empty, root only, or root + one LEFT leaf. No right child.
    // TODO: create a new root; if the source has a left child, copy that too.
    // The child belongs at this object's root->left, not at root itself.
    throw std::logic_error("Not implemented");
}
