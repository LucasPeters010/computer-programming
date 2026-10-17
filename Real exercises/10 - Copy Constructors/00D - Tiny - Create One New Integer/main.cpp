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
            int* first = makeNumber(value);
            int* second = makeNumber(value);
            check(first != nullptr && second != nullptr, "return valid pointers");
            check(first != second, "each call allocates a DIFFERENT integer");
            check(*first == value && *second == value, "initialize both integers");
            *first = 42;
            check(*second == value, "separate allocations are independent");
            delete first;
            check(*second == value, "deleting one leaves the other alive");
            delete second;
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
