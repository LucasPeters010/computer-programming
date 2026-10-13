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

class SeatRow {
public:
    SeatRow(int n);
    int reserve(int bookingId, int count);
    int cancel(int bookingId);
    bool contains(int bookingId) const;
    int occupied() const;
    std::string layout() const;

private:
    // Choose fields and helper declarations.
};

class Train {
public:
    Train(int rowCount, int seatsPerRow);
    int book(int bookingId, int count);
    int cancel(int bookingId);
    std::string layout() const;

private:
    // Choose fields and helper declarations.
};
