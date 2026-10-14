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

class MiniVector {
public:
    MiniVector();
    ~MiniVector();
    int size() const;
    int capacity() const;
    int& at(int index);
    void resize(int n);
    MiniVector(const MiniVector&) = delete;
    MiniVector& operator=(const MiniVector&) = delete;

private:
    int* data;
    int length;
    int allocated;
    // Add helper declarations if needed.
};
