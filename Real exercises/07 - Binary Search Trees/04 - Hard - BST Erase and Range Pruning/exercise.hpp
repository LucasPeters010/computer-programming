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

class MutableTree {
public:
    MutableTree();
    ~MutableTree();
    void insert(int key);
    bool erase(int key);
    int retainRange(int low, int high);
    int size() const;
    int height() const;
    std::vector<int> inOrder() const;
    MutableTree(const MutableTree&) = delete;
    MutableTree& operator=(const MutableTree&) = delete;

private:
    // Choose fields and helper declarations.
};
