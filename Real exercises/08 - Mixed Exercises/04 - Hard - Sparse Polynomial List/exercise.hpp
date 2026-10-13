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

class Polynomial {
public:
    Polynomial();
    ~Polynomial();
    void addTerm(int coefficient, int exponent);
    void addFrom(const Polynomial& other);
    long long evaluate(int x) const;
    std::string terms() const;
    void load(std::istream& input);
    Polynomial(const Polynomial&) = delete;
    Polynomial& operator=(const Polynomial&) = delete;

private:
    // Choose fields and helper declarations.
};
