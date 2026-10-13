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

class LinkedQueue {
public:
    LinkedQueue();
    ~LinkedQueue();
    void push(int value);
    int front() const;
    int pop();
    int size() const;
    int transferTo(LinkedQueue& other, int count);
    std::vector<int> toVector() const;
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

private:
    // Choose fields and helper declarations.
};
