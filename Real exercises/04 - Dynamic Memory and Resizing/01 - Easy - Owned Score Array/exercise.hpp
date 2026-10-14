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

class ScoreArray {
public:
    ScoreArray(int n);
    ~ScoreArray();
    int& at(int index);
    int sum() const;
    ScoreArray(const ScoreArray&) = delete;
    ScoreArray& operator=(const ScoreArray&) = delete;

private:
    int* data;
    int length;
    // Add helper declarations if needed.
};
