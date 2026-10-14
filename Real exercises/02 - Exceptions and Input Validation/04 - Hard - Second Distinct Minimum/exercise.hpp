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

class TooFewValues {
public:
    TooFewValues(int n);
    int count() const;

private:
    int supplied;
    // Add helper declarations if needed.
};

class AllEqual {
public:
    AllEqual(int repeated);
    int value() const;

private:
    int repeated;
    // Add helper declarations if needed.
};

int secondMinimum(const std::vector<int>& values);
