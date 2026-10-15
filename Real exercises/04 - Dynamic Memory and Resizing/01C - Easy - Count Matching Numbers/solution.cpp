#include "exercise.hpp"

NumberArray::NumberArray(int n) {
    // TODO: save n as the length and allocate n integers initialized to zero.
    (void)n;
    throw std::logic_error("Not implemented");
}

NumberArray::~NumberArray() {
    // TODO: release your dynamic array. Do not throw from this function.
}

int& NumberArray::at(int index) {
    // TODO: check the index before accessing data, then return the element.
    (void)index;
    throw std::logic_error("Not implemented");
}

int NumberArray::count(int value) const {
    // TODO: count how many elements equal value. Start your counter at zero.
    (void)value;
    throw std::logic_error("Not implemented");
}
