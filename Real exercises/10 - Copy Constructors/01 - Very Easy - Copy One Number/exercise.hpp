#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class Counter {
public:
    explicit Counter(int n) : value(n) {}
    int get() const { return value; }
    void set(int n) { value = n; }
    Counter(const Counter& other);
    Counter& operator=(const Counter&) = delete;
private:
    int value;
};
