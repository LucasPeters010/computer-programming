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
        for (int value : {9, 0, -7, INT_MAX}) {
            const int source = value;
            int destination = 123;
            copyValue(&source, &destination);
            check(destination == value, "copy the stored integer");
            destination = 42;
            check(source == value, "changing the copy leaves source alone");
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
