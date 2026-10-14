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

class ReportTree {
public:
    ReportTree();
    ~ReportTree();
    void insert(int key);
    long long sum() const;
    std::vector<int> inOrder() const;
    ReportTree(const ReportTree&) = delete;
    ReportTree& operator=(const ReportTree&) = delete;

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

void writeTreeReport(std::istream& input, std::ostream& output);
