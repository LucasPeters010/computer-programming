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

class PathTree {
public:
    PathTree();
    ~PathTree();
    void insert(int key);
    bool isHeightBalanced() const;
    int diameter() const;
    std::vector<int> pathBetween(int a, int b) const;
    PathTree(const PathTree&) = delete;
    PathTree& operator=(const PathTree&) = delete;

private:
    // Choose fields and helper declarations.
};
