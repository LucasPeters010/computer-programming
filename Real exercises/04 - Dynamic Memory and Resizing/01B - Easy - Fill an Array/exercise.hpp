#pragma once
#include <stdexcept>

class FillArray {
public:
    FillArray(int n);
    ~FillArray();
    void fill(int value);
    int get(int index) const { return data[index]; } // Supplied; valid indices only.
    // Supplied: prevents accidental copying of owned memory. Leave unchanged.
    FillArray(const FillArray&) = delete;
    FillArray& operator=(const FillArray&) = delete;
private:
    int* data = nullptr;
    int length = 0;
};
