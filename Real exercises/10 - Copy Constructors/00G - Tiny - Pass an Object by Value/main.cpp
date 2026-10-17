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
        TinyCounter original(9);
        for (int value : {25, 0, -7}) {
            check(changeLocal(original, value) == value, "change the local copy");
            check(original.get() == 9, "pass by value preserves the original object");
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
