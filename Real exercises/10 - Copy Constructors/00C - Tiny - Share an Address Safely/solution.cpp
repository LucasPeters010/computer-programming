#include "exercise.hpp"

// This exercise INTENTIONALLY shares an address so you can see a shallow copy.
// main.cpp uses an ordinary local int, with NO owning objects or deletes.
// Merely pointing at an int does not make this pointer responsible for deleting it.
int* sameAddress(int* original) {
    (void)original;
    // Return the same POINTER (one statement). No new, no delete, no * needed.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
}
