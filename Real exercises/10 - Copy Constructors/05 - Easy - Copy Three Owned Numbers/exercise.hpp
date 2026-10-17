#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class Triple {
public:
    Triple(int a, int b, int c) : data(new int[3]{a, b, c}) {}
    ~Triple() { delete[] data; }
    int& at(int index) {
        if (index < 0 || index >= 3) throw std::out_of_range("Invalid index");
        return data[index];
    }
    const int& at(int index) const {
        if (index < 0 || index >= 3) throw std::out_of_range("Invalid index");
        return data[index];
    }
    Triple(const Triple& other);
    Triple& operator=(const Triple&) = delete;
private:
    int* data;
};
