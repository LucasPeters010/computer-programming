#include "exercise.hpp"

IntBox::IntBox(const IntBox& other) : data(nullptr) {
    // TODO: Allocate one new integer for the copy and give it the source integer's value. Each IntBox must own a different allocation.
    (void)other;
    throw std::logic_error("Not implemented");
}
