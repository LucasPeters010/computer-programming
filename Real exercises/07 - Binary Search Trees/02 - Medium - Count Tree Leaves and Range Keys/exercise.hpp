#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// Preserve the public signatures; use the supplied private fields and add helpers if needed.

class Tree {
public:
    Tree();
    ~Tree();
    void insert(int key);
    int leafCount() const;
    int countBetween(int low, int high) const;
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

private:
    class Node {
    public:
        Node(int key) : key(key), left(nullptr), right(nullptr) {}
        int key;
        Node* left;
        Node* right;
    };
    Node* root;
    void destroy(Node* node);
    // Add helper declarations if needed.
};
