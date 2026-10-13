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

class IntList {
public:
    IntList();
    ~IntList();
    void append(int value);
    int removeAll(int value);
    void reverse();
    bool contains(int value) const;
    int size() const;
    std::vector<int> toVector() const;
    IntList(const IntList&) = delete;
    IntList& operator=(const IntList&) = delete;

private:
    // Choose fields and helper declarations.
};
