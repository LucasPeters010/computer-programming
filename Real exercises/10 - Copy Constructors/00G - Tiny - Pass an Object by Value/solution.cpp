#include "exercise.hpp"

// There is NO & after TinyCounter: local is a separate object.
// C++ calls the supplied copy constructor BEFORE entering this function.
// The caller's object stays alive while this local copy exists.
int changeLocal(TinyCounter local, int replacement) {
    (void)local; (void)replacement;
    // Two statements: set local's number to replacement, then return local.get().
    // When the function finishes, local is destroyed automatically.
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
}
