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
        int number = 9;
        int* first = &number;
        int* second = sameAddress(first);
        check(first == second, "both pointers must hold the SAME address");
        *second = 25;
        check(number == 25 && *first == 25, "both pointers reach the same integer");
        *first = -8;
        check(*second == -8, "sharing works in both directions");
        // No delete: number was never created with new.
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
