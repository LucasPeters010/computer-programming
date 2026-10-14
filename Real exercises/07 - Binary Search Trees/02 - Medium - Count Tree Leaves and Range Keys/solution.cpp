#include "exercise.hpp"

// Add private fields/helpers in exercise.hpp and implementations here.

Tree::Tree() : root(nullptr) {}

Tree::~Tree() { destroy(root); }

void Tree::insert(int key) {
    if (root == nullptr) { root = new Node(key); return; }
    Node* current = root;
    while (true) {
        if (key == current->key) return;
        if (key < current->key) {
            if (current->left == nullptr) { current->left = new Node(key); return; }
            current = current->left;
        } else {
            if (current->right == nullptr) { current->right = new Node(key); return; }
            current = current->right;
        }
    }
}

int Tree::leafCount() const {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

int Tree::countBetween(int low, int high) const {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}


// Provided infrastructure; this function is not an exercise task.
void Tree::destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
