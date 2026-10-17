#include "exercise.hpp"

// The caller already owns an integer; address points to it.
// Assigning to *address changes that integer.
// Assigning to address would change only this local pointer.
void writeNumber(int* address, int replacement) {
    (void)address; (void)replacement;
    // Store replacement in the existing integer (one statement).
    // Do NOT use new or delete here.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
}
