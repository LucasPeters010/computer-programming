#include "exercise.hpp"

// This ordinary class carries TWO facts about the invalid entry.
// Creating an object stores information; throwing it reports the error.
InvalidQuantity::InvalidQuantity(int index, int quantity) {
    (void)index; (void)quantity;
    throw std::logic_error("Not implemented");
}
int InvalidQuantity::position() const {
    throw std::logic_error("Not implemented");
}
int InvalidQuantity::value() const {
    throw std::logic_error("Not implemented");
}
long long checkedTotal(const std::vector<int>& quantities) {
    // Validate from left to right. Report the first bad entry only.
    (void)quantities;
    throw std::logic_error("Not implemented");
}
