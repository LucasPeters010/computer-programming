#pragma once
#include <stdexcept>

#include <iostream>
class OwnedNumber {
public:
    explicit OwnedNumber(int n) : data(new int(n)) { ++liveIntegers; }
    // Supplied deep copy: two owners get TWO different allocations.
    OwnedNumber(const OwnedNumber& other) : data(new int(*other.data)) { ++liveIntegers; }
    ~OwnedNumber() noexcept(false); // Allows the starter's Not implemented message.
    int get() const { return *data; }
    void set(int n) { *data = n; }
    static int liveCount() { return liveIntegers; }
    OwnedNumber& operator=(const OwnedNumber&) = delete;
private:
    int* data;
    inline static int liveIntegers = 0;
};
