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
        IntSequence s;
        s.insert(0,10); s.insert(1,30); s.insert(1,20); s.insert(0,5);
        check(s.toVector()==std::vector<int>({5,10,20,30}) && s.capacity()==4,"insert order and growth");
        check(s.erase(1)==10 && s.capacity()==4,"erase returns value");
        s.eraseRange(1,3); check(s.toVector()==std::vector<int>({5}),"range erase");
        expect<std::out_of_range>([&]{s.insert(3,9);},"Index out of range");
        expect<std::out_of_range>([&]{s.eraseRange(1,0);},"Invalid range");
        s.eraseRange(0,1); check(s.size()==0 && s.capacity()==4,"erase everything");
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
