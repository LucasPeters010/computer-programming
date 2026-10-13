#include "exercise.hpp"

// Public smoke checks, not an exhaustive grading suite. Add your own cases.
namespace {
void check(bool condition, const std::string& label) {
    if (!condition) throw std::runtime_error("Check failed: " + label);
}
[[maybe_unused]] bool close(double a, double b) {
    return std::abs(a-b) < 1e-9;
}
template<class Error, class Action>
void expect(Action action, const std::string& message) {
    try { action(); }
    catch (const Error& e) {
        check(std::string(e.what()) == message, "exception message: " + message);
        return;
    }
    throw std::runtime_error("Expected exception: " + message);
}
}

int main() {
    try {
        IntVector v(3); v.at(0)=8; v.at(1)=5; v.at(2)=2;
        v.reserve(6); check(v.size()==3 && v.capacity()==6,"reserve preserves size");
        v.resize(1); v.resize(4);
        check(v.toVector()==std::vector<int>({8,0,0,0}) && v.capacity()==6,"shrink then grow resets values");
        v.resize(8); check(v.capacity()==8 && v.at(0)==8 && v.at(7)==0,"reallocation");
        expect<std::out_of_range>([&]{v.at(8);},"Index out of range");
        expect<std::out_of_range>([&]{v.resize(-1);},"Negative size");
        v.resize(0); check(v.size()==0 && v.capacity()==8,"zero logical size");
        std::cout << "Public checks passed. Add the edge cases from README.md.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unexpected uncaught custom exception.\n";
        return 1;
    }
}
