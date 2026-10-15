#include "exercise.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    try {
        // Example from README: this prints your actual results.
        {
            ZeroArray a(4);
            std::cout << a.size() << "\n";
            std::cout << a.get(0) << " " << a.get(3) << "\n";
        }
        // Checks for different sizes and boundary cases.
        {
        ZeroArray a(4);
        assert(a.size() == 4);
        for (int i = 0; i < 4; ++i) assert(a.get(i) == 0);
        ZeroArray b(1);
        assert(b.size() == 1 && b.get(0) == 0);
        ZeroArray empty(0);
        assert(empty.size() == 0);
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cout << "Not finished: " << e.what() << "\n";
        return 1;
    }
}
