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
        NumberBuffer b(4);
        for(int i=0;i<4;++i) b.at(i)=i+1;
        b.shiftRight(2,-1);
        check(b.toVector()==std::vector<int>({-1,-1,1,2}), "overlapping shift");
        const NumberBuffer& view=b; check(view.at(3)==2, "const access");
        expect<std::out_of_range>([&]{b.at(4);}, "Index out of range");
        expect<std::invalid_argument>([&]{b.shiftRight(-1,0);}, "Negative shift");
        b.shiftRight(9,7); check(b.toVector()==std::vector<int>({7,7,7,7}), "large shift");
        NumberBuffer empty(0); empty.shiftRight(2,1); check(empty.size()==0, "empty buffer");
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
