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

class RouteMap {
public:
    RouteMap(const std::vector<std::string>& grid);
    int rows() const;
    int cols() const;
    std::vector<std::string> shortestVia(int checkRow, int checkCol) const;

private:
    // Choose fields and helper declarations.
};
