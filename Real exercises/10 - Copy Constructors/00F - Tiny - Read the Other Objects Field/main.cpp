#include "exercise.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
void check(bool ok, const char* message) {
    // Immediate exit avoids running destructors on known-bad shared storage.
    if (!ok) { std::cerr << "FAIL: " << message << std::endl; std::exit(1); }
}
int main() {
    try {
        for (int value : {9, 0, -7}) {
            const TinyCounter original(value);
            TinyCounter copy(original); // Calls YOUR copy constructor.
            check(copy.get() == value, "read the existing object's number");
            copy.set(25);
            check(original.get() == value, "ordinary int fields are independent");
            TinyCounter third = copy; // Also construction, not assignment.
            check(third.get() == 25, "copy construction using = syntax");
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
