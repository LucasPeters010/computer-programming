#include "exercise.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    try {
        // Example from README: this prints your actual results.
        {
            FillArray a(3);
            a.fill(7);
            std::cout << a.get(0) << " " << a.get(1) << " " << a.get(2) << "\n";
            a.fill(-2);
            std::cout << a.get(0) << "\n";
        }
        // Checks for different sizes and boundary cases.
        {
        FillArray a(3);
        assert(a.get(0) == 0 && a.get(2) == 0);
        a.fill(7);
        for (int i = 0; i < 3; ++i) assert(a.get(i) == 7);
        a.fill(-2);
        for (int i = 0; i < 3; ++i) assert(a.get(i) == -2);
        FillArray b(1);
        b.fill(9);
        assert(b.get(0) == 9);
        FillArray empty(0);
        empty.fill(5);
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cout << "Not finished: " << e.what() << "\n";
        return 1;
    }
}
