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

class Calculator {
public:
    Calculator();
    int value() const;
    std::string execute(const std::string& line);

private:
    // Choose fields and helper declarations.
};

void runCalculator(std::istream& input, std::ostream& output);
