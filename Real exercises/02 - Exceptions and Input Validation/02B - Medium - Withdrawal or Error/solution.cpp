#include "exercise.hpp"

// An exception object carries the requested amount and available balance.
InsufficientFunds::InsufficientFunds(int requested, int available) {
    (void)requested; (void)available;
    throw std::logic_error("Not implemented");
}
int InsufficientFunds::requestedAmount() const {
    throw std::logic_error("Not implemented");
}
int InsufficientFunds::availableAmount() const {
    throw std::logic_error("Not implemented");
}
int withdraw(int balance, int amount) {
    // Check the rules in README order. Return the remaining balance on success.
    // balance and amount are ordinary integers passed by value.
    (void)balance; (void)amount;
    throw std::logic_error("Not implemented");
}
