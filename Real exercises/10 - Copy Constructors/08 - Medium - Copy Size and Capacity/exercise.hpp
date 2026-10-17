#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class CopyBuffer {
public:
    explicit CopyBuffer(int capacity) : data(capacity > 0 ? new int[capacity]{} : nullptr), length(0), allocated(capacity) {}
    ~CopyBuffer() { delete[] data; }
    int size() const { return length; }
    int capacity() const { return allocated; }
    void push(int value) {
        if (length == allocated) throw std::runtime_error("Buffer is full");
        data[length] = value;
        ++length;
    }
    int& at(int index) {
        if (index < 0 || index >= length) throw std::out_of_range("Invalid index");
        return data[index];
    }
    const int& at(int index) const {
        if (index < 0 || index >= length) throw std::out_of_range("Invalid index");
        return data[index];
    }
    CopyBuffer(const CopyBuffer& other);
    CopyBuffer& operator=(const CopyBuffer&) = delete;
private:
    int* data;
    int length;
    int allocated;
};
