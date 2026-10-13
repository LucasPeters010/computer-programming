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

class TooFewValues {
public:
    TooFewValues(int supplied);
    int count() const;

private:
    // Choose fields and helper declarations.
};

class NoDistinctValue {
public:
    NoDistinctValue(int repeated);
    int value() const;

private:
    // Choose fields and helper declarations.
};

int secondDistinctMinimum(const std::vector<int>& values);
