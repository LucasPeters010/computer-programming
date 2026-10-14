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

class Buffer {
public:
    Buffer(int n);
    ~Buffer();
    int size() const;
    int& at(int index);
    void resize(int n);
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

private:
    int* data;
    int length;
    // Add helper declarations if needed.
};
