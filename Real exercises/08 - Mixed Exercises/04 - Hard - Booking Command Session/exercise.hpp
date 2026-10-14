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

class BookingDesk {
public:
    BookingDesk();
    bool book(int start, int end);
    int hours() const;

private:
    std::vector<int> startHours;
    std::vector<int> endHours;
    // Add helper declarations if needed.
};

void runBookings(std::istream& input, std::ostream& output);
