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

class ImportError {
public:
    ImportError(int lineNumber, std::string reason);
    int line() const;
    std::string message() const;

private:
    // Choose fields and helper declarations.
};

class ScoreStore {
public:
    ScoreStore();
    void importScores(std::istream& input);
    int size() const;
    int scoreFor(int id) const;
    std::string report() const;

private:
    // Choose fields and helper declarations.
};
