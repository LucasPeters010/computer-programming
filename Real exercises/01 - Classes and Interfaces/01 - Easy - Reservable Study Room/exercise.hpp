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

class StudyRoom {
public:
    StudyRoom(std::string name);
    bool reserve(int start, int end);
    bool cancel(int start, int end);
    bool isFree(int start, int end) const;
    int bookedHours() const;
    std::string schedule() const;

private:
    // Choose fields and helper declarations.
};
