#include "exercise.hpp"

// Add private fields/helpers in exercise.hpp and implementations here.

ReportTree::ReportTree() : root(nullptr) {}

ReportTree::~ReportTree() { destroy(root); }

void ReportTree::insert(int key) {
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

long long ReportTree::sum() const {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

std::vector<int> ReportTree::inOrder() const {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

void writeTreeReport(std::istream& input, std::ostream& output) {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}


// Provided infrastructure; this function is not an exercise task.
void ReportTree::destroy(Node* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
