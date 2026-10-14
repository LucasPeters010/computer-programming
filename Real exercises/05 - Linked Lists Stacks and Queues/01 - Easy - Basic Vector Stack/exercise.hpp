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

class IntStack {
public:
    IntStack();
    void push(int value);
    int top() const;
    int pop();
    bool isEmpty() const;

private:
    std::vector<int> values;
    // Add helper declarations if needed.
};
