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

class ExamStack {
public:
    ExamStack(int capacity);
    ~ExamStack();
    void push(int value);
    int pop();
    int top() const;
    int size() const;
    ExamStack(const ExamStack&) = delete;
    ExamStack& operator=(const ExamStack&) = delete;

private:
    int* data;
    int limit;
    int count;
    // Add helper declarations if needed.
};

void runStack(std::istream& input, std::ostream& output, int capacity);
