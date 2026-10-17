#include "exercise.hpp"

// Unlike 00C, you must create NEW storage here.
// new int(value) allocates one integer and initializes it with value.
// Return its address so main.cpp can use it and eventually delete it.
int* makeNumber(int value) {
    (void)value;
    // Return a new integer initialized with value (one statement).
    // Do not return the address of a local variable: it would stop existing.
    // Do not delete the allocation before returning it.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
}
