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

class StudyRoom {
public:
    StudyRoom();
    bool reserve(int start, int end);
    bool isFree(int start, int end) const;
    int bookedHours() const;

private:
    std::vector<int> startHours;
    std::vector<int> endHours;
    // Add helper declarations if needed.
};
