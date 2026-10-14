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

class NumberArray {
public:
    NumberArray(int n);
    ~NumberArray();
    int& at(int index);
    int total() const;
    NumberArray(const NumberArray&) = delete;
    NumberArray& operator=(const NumberArray&) = delete;

private:
    int* data;
    int length;
    // Add helper declarations if needed.
};
