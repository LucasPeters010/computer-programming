#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <climits>

// Preserve these signatures; implement the functions in solution.cpp.
class InvalidQuantity {
public:
    InvalidQuantity(int index, int quantity);
    int position() const;
    int value() const;
private:
    int index;
    int quantity;
};
long long checkedTotal(const std::vector<int>& quantities);
