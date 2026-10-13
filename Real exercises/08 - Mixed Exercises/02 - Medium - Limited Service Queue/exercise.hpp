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

class Request {
public:
    Request(int id, std::string description);
    int getId() const;
    std::string toString() const;

private:
    // Choose fields and helper declarations.
};

class ServiceQueue {
public:
    ServiceQueue(int limit);
    ~ServiceQueue();
    void add(int id, std::string description);
    std::string serve();
    bool cancel(int id);
    int size() const;
    std::string listing() const;
    ServiceQueue(const ServiceQueue&) = delete;
    ServiceQueue& operator=(const ServiceQueue&) = delete;

private:
    // Choose fields and helper declarations.
};
