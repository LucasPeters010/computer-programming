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

class TicketOffice {
public:
    TicketOffice(int capacity);
    bool reserve(int amount);
    bool cancel(int amount);
    int available() const;
    int reserved() const;

private:
    int totalTickets;
    int reservedTickets;
    // Add helper declarations if needed.
};
