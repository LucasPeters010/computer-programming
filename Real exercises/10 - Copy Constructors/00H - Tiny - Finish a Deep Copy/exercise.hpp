#pragma once
#include <stdexcept>

class OwnedNumber {
public:
    explicit OwnedNumber(int n) : data(new int(n)) {}
    OwnedNumber(const OwnedNumber& other);
    ~OwnedNumber() { delete data; }
    int get() const { return *data; }
    void set(int n) { *data = n; }
    const int* address() const { return data; }
    OwnedNumber& operator=(const OwnedNumber&) = delete;
private:
    int* data;
};
