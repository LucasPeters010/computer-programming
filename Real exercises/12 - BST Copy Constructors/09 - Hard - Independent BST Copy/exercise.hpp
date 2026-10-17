#pragma once
#include <stdexcept>
#include <string>
#include <vector>

// Node is a TYPE declared inside BST. root points to a separately allocated Node.
// A BST object does not automatically contain a Node object.
class BST {
public:
    BST() : root(nullptr) {}
    ~BST() { delete root; } // Node's destructor handles its own children.
    BST(const BST& other);
    BST& operator=(const BST&) = delete; // Assignment is not this exercise.

    // Supplied infrastructure: do not implement insertion or lookup again.
    void insert(int key, const std::string& value) { insertAt(root, key, value); }
    std::string getValue(int key) const {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->key) return current->value;
            current = key < current->key ? current->left : current->right;
        }
        throw std::out_of_range("BST");
    }
    std::vector<int> preOrder() const {
        std::vector<int> result;
        appendPreOrder(root, result);
        return result;
    }

private:
    class Node {
    public:
        int key;
        std::string value;
        Node* left;
        Node* right;
        Node(int k, const std::string& v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
        ~Node() { delete left; delete right; }
    };
    Node* root;
    // You may declare your own private helper here.

    static void insertAt(Node*& node, int key, const std::string& value) {
        if (node == nullptr) { node = new Node(key, value); return; }
        if (key == node->key) { node->value = value; return; }
        if (key < node->key) insertAt(node->left, key, value);
        else insertAt(node->right, key, value);
    }
    static void appendPreOrder(const Node* node, std::vector<int>& out) {
        if (node == nullptr) return;
        out.push_back(node->key);
        appendPreOrder(node->left, out);
        appendPreOrder(node->right, out);
    }
    friend struct TestAccess; // Test-only access; not part of your solution.
};
