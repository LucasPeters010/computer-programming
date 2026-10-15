#pragma once
#include <stdexcept>

class ZeroArray {
public:
    ZeroArray(int n);
    ~ZeroArray();
    int get(int index) const { return data[index]; } // Supplied; valid indices only.
    int size() const { return length; } // Supplied.
    // Supplied: prevents accidental copying of owned memory. Leave unchanged.
    ZeroArray(const ZeroArray&) = delete;
    ZeroArray& operator=(const ZeroArray&) = delete;
private:
    int* data = nullptr;
    int length = 0;
};
