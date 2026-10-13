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

class CheckpointStack {
public:
    CheckpointStack();
    void push(int value);
    int top() const;
    int pop();
    int size() const;
    bool isEmpty() const;
    int mark() const;
    void rollback(int checkpoint);
    std::string toString() const;

private:
    // Choose fields and helper declarations.
};
