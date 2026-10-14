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

class ExamTree {
public:
    ExamTree();
    ~ExamTree();
    void insert(int key);
    bool contains(int key) const;
    std::vector<int> inOrder() const;
    int height() const;
    ExamTree(const ExamTree&) = delete;
    ExamTree& operator=(const ExamTree&) = delete;

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

void treeSummary(std::istream& input, std::ostream& output);
