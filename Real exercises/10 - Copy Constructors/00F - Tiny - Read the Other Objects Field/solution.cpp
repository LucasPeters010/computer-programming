#include "exercise.hpp"

// This constructor builds a NEW TinyCounter from an EXISTING one.
// number       = the new object's field.
// other.number = the existing object's field.
// A class can access private fields in another object of the same class.
TinyCounter::TinyCounter(const TinyCounter& other) : number(0) {
    (void)other;
    // Copy other.number into number (one statement).
    // This is an ordinary int, so no new or delete is needed.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
}
