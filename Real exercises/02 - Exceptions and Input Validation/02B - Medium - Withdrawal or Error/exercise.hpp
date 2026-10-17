#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <climits>

// Preserve these signatures; implement the functions in solution.cpp.
class InsufficientFunds {
public:
    InsufficientFunds(int requested, int available);
    int requestedAmount() const;
    int availableAmount() const;
private:
    int requested;
    int available;
};
int withdraw(int balance, int amount);
