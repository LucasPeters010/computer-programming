#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class IntBox {
public:
    explicit IntBox(int n) : data(new int(n)) {}
    ~IntBox() { delete data; }
    int& at() { return *data; }
    const int& at() const { return *data; }
    IntBox(const IntBox& other);
    IntBox& operator=(const IntBox&) = delete;
private:
    int* data;
};
