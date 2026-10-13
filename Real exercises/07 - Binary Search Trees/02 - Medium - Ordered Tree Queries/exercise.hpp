#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Preserve the public signatures; choose your own private representation.

class OrderedTree {
public:
    OrderedTree();
    ~OrderedTree();
    void insert(int key);
    std::vector<int> inOrder() const;
    int height() const;
    int kthSmallest(int k) const;
    int floorKey(int key) const;
    int ceilingKey(int key) const;
    OrderedTree(const OrderedTree&) = delete;
    OrderedTree& operator=(const OrderedTree&) = delete;

private:
    // Choose fields and helper declarations.
};
