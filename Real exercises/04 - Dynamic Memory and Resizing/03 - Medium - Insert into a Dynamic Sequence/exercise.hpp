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

class Sequence {
public:
    Sequence();
    ~Sequence();
    void insert(int index, int value);
    int at(int index) const;
    int size() const;
    Sequence(const Sequence&) = delete;
    Sequence& operator=(const Sequence&) = delete;

private:
    int* data;
    int length;
    // Add helper declarations if needed.
};
