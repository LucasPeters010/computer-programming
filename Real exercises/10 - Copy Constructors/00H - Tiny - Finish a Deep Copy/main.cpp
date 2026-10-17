#include "exercise.hpp"
#include <iostream>
#include <cstdlib>
void check(bool ok, const char* message) {
    if (!ok) { std::cerr << "FAIL: " << message << std::endl; std::exit(1); }
}
int main() {
    try {
        for (int value : {9, 0, -7}) {
            OwnedNumber original(value);
            OwnedNumber copy(original);
            check(copy.address() != nullptr, "allocate an integer");
            check(copy.address() != original.address(), "do not share the source address");
            check(copy.get() == value, "copy the number");
            copy.set(25);
            check(original.get() == value, "copy change leaves original alone");
            original.set(42);
            check(copy.get() == 25, "original change leaves copy alone");
            const OwnedNumber third(copy);
            check(third.address() != copy.address() && third.get() == 25, "copy of copy");
        }
        OwnedNumber* source = new OwnedNumber(9);
        OwnedNumber survivor(*source);
        check(source->address() != survivor.address(), "different storage before delete");
        delete source;
        check(survivor.get() == 9, "copy survives source deletion");
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n'; return 1;
    }
}
