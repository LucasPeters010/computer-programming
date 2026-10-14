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

class SearchTree {
public:
    SearchTree();
    ~SearchTree();
    void insert(int key);
    bool contains(int key) const;
    std::vector<int> inOrder() const;
    SearchTree(const SearchTree&) = delete;
    SearchTree& operator=(const SearchTree&) = delete;

private:
    class Node {
    public:
        Node(int key) : key(key), left(nullptr), right(nullptr) {}
        int key;
        Node* left;
        Node* right;
    };
    Node* root;
    // Add helper declarations if needed.
};
