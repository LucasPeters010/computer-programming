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

class ScoreList {
public:
    ScoreList();
    void add(int score);
    double average() const;
    int passingCount() const;

private:
    std::vector<int> scores;
    // Add helper declarations if needed.
};
