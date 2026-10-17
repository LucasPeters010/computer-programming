#include "exercise.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
void check(bool ok, const char* message) {
    // Immediate exit avoids running destructors on known-bad shared storage.
    if (!ok) { std::cerr << "FAIL: " << message << std::endl; std::exit(1); }
}
// Supplied function: focus on the lifetime trace, not on implementing this.
void visit(OwnedNumber local) {
    check(OwnedNumber::liveCount() == 2, "copy has its own allocation");
    local.set(25);
    std::cout << "Inside function: local = " << local.get() << '\n';
}
int main() {
    try {
        // Only one object is pending destruction on the starter's first throw.
        // This early probe prevents a second throwing destructor during unwinding.
        { OwnedNumber probe(0); }
        check(OwnedNumber::liveCount() == 0, "probe was destroyed");
        {
            OwnedNumber original(9);
            std::cout << "Original created; integers alive: " << OwnedNumber::liveCount() << '\n';
            // Passing by value constructs a separate local object.
            visit(original);
            check(OwnedNumber::liveCount() == 1, "local object was destroyed on return");
            check(original.get() == 9, "original is still alive and unchanged");
            std::cout << "After function: original = " << original.get() << '\n';
        } // Original's destructor runs here.
        check(OwnedNumber::liveCount() == 0, "both object lifetimes have finished");
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
