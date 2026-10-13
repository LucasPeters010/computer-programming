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

class IntSequence {
public:
    IntSequence();
    ~IntSequence();
    int size() const;
    int capacity() const;
    void insert(int index, int value);
    int erase(int index);
    void eraseRange(int first, int last);
    std::vector<int> toVector() const;
    IntSequence(const IntSequence&) = delete;
    IntSequence& operator=(const IntSequence&) = delete;

private:
    // Choose fields and helper declarations.
};
