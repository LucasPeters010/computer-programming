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

class SummaryTree {
public:
    SummaryTree();
    ~SummaryTree();
    bool insert(int key);
    bool contains(int key) const;
    long long sum() const;
    int leafCount() const;
    long long rangeSum(int low, int high) const;
    SummaryTree(const SummaryTree&) = delete;
    SummaryTree& operator=(const SummaryTree&) = delete;

private:
    // Choose fields and helper declarations.
};
