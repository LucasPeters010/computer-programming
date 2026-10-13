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

class ValueStack {
public:
    ValueStack();
    ~ValueStack();
    void push(double value);
    double pop();
    double top() const;
    int size() const;
    ValueStack(const ValueStack&) = delete;
    ValueStack& operator=(const ValueStack&) = delete;

private:
    // Choose fields and helper declarations.
};

double evaluatePostfix(const std::string& expression);
