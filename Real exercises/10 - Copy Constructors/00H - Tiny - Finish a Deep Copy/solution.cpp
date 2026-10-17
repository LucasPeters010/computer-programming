#include "exercise.hpp"

// This constructor builds a new owner. other is the existing owner.
OwnedNumber::OwnedNumber(const OwnedNumber& other) : data(nullptr) {
    // Step 1 (YOUR one line): give data a NEW integer allocation.
    // Do NOT copy other.data: that would share the source's address.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END

    // Step 2 (SUPPLIED): copy the number, exactly like warm-up 00E.
    *data = *other.data;
    // Each object's supplied destructor will delete its OWN allocation.
}
