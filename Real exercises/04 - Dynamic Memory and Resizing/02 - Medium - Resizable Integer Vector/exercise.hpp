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

class IntVector {
public:
    IntVector(int n);
    ~IntVector();
    int size() const;
    int capacity() const;
    int& at(int index);
    void resize(int n);
    void reserve(int n);
    std::vector<int> toVector() const;
    IntVector(const IntVector&) = delete;
    IntVector& operator=(const IntVector&) = delete;

private:
    // Choose fields and helper declarations.
};
