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

class TransactionError {
public:
    TransactionError(int lineNumber, std::string reason);
    int line() const;
    std::string message() const;

private:
    // Choose fields and helper declarations.
};

int applyTransaction(int balance, const std::string& text, int lineNumber);

int processLog(std::istream& input, std::ostream& errors);
