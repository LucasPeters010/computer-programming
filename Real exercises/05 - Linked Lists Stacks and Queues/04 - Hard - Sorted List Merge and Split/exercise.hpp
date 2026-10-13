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

class SortedList {
public:
    SortedList();
    ~SortedList();
    void insert(int value);
    int size() const;
    void mergeFrom(SortedList& other);
    void splitAt(int pivot, SortedList& destination);
    std::vector<int> toVector() const;
    SortedList(const SortedList&) = delete;
    SortedList& operator=(const SortedList&) = delete;

private:
    // Choose fields and helper declarations.
};
