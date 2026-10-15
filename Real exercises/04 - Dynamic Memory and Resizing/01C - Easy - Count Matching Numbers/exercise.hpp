#pragma once
#include <stdexcept>

class NumberArray {
public:
    NumberArray(int n);
    ~NumberArray();
    int& at(int index);
    int count(int value) const;
    // Supplied: prevents accidental copying of owned memory. Leave unchanged.
    NumberArray(const NumberArray&) = delete;
    NumberArray& operator=(const NumberArray&) = delete;
private:
    int* data = nullptr;
    int length = 0;
};
