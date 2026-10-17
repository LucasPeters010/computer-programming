#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class NumberArray {
public:
    explicit NumberArray(int n) : data(n > 0 ? new int[n]{} : nullptr), length(n) {}
    ~NumberArray() { delete[] data; }
    int size() const { return length; }
    int& at(int index) {
        if (index < 0 || index >= length) throw std::out_of_range("Invalid index");
        return data[index];
    }
    const int& at(int index) const {
        if (index < 0 || index >= length) throw std::out_of_range("Invalid index");
        return data[index];
    }
    NumberArray(const NumberArray& other);
    NumberArray& operator=(const NumberArray&) = delete;
private:
    int* data;
    int length;
};
