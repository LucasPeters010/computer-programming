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

class InvalidScore {
public:
    InvalidScore(int index);
    int position() const;

private:
    int index;
    // Add helper declarations if needed.
};

double checkedAverage(const std::vector<int>& scores);
