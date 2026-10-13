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

class NumberBuffer {
public:
    NumberBuffer(int n);
    ~NumberBuffer();
    int size() const;
    int& at(int index);
    const int& at(int index) const;
    void shiftRight(int steps, int fill);
    std::vector<int> toVector() const;
    NumberBuffer(const NumberBuffer&) = delete;
    NumberBuffer& operator=(const NumberBuffer&) = delete;

private:
    // Choose fields and helper declarations.
};
