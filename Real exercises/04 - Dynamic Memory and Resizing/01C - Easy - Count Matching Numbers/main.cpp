#include "exercise.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    try {
        // Example from README: this prints your actual results.
        {
            NumberArray a(4);
            a.at(0) = 5;
            a.at(2) = 5;
            std::cout << a.count(5) << "\n";
            std::cout << a.count(0) << "\n";
            std::cout << a.count(9) << "\n";
        }
        // Checks for different sizes and boundary cases.
        {
        NumberArray a(4);
        assert(a.count(0) == 4);
        a.at(0) = 5;
        a.at(2) = 5;
        assert(a.count(5) == 2 && a.count(0) == 2 && a.count(9) == 0);
        a.at(3) = -1;
        assert(a.count(-1) == 1);
        for (int index : {-1, 4}) {
            bool caught = false;
            try { a.at(index); }
            catch (const std::out_of_range& e) { caught = std::string(e.what()) == "Invalid index"; }
            assert(caught);
        }
        NumberArray empty(0);
        assert(empty.count(0) == 0);
        bool caught = false;
        try { empty.at(0); }
        catch (const std::out_of_range&) { caught = true; }
        assert(caught);
        }
        std::cout << "All checks passed!\n";
    } catch (const std::exception& e) {
        std::cout << "Not finished: " << e.what() << "\n";
        return 1;
    }
}
