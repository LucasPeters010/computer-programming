#include "exercise.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>

// Exit immediately on failure: a shallow copy must not reach two destructors.
void check(bool ok, const char* message) {
    if (!ok) { std::cerr << "FAIL: " << message << std::endl; std::exit(1); }
}
int main() {
    try {
        for (int value : {0, 7, -8, INT_MIN, INT_MAX}) {
            const Counter original(value);
            Counter copy(original);
            check(copy.get() == value, "copy the original value");
            copy.set(42);
            check(original.get() == value, "changing copy leaves original unchanged");
            Counter third = original;
            check(third.get() == value, "initialization with = also copies");
        }
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
