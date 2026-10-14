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

class ScoreRegister {
public:
    ScoreRegister();
    bool add(int score);
    double average() const;
    int countAtLeast(int limit) const;

private:
    std::vector<int> scores;
    // Add helper declarations if needed.
};
