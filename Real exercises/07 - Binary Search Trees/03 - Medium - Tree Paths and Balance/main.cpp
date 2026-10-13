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
        PathTree t;
        for(int x:std::vector<int>({8,4,12,2,6,10,14})) t.insert(x);
        check(t.isHeightBalanced() && t.diameter()==5,"balanced tree properties");
        check(t.pathBetween(2,10)==std::vector<int>({2,4,8,12,10}),"cross-root path");
        check(t.pathBetween(6,4)==std::vector<int>({6,4}) && t.pathBetween(8,8)==std::vector<int>({8}),"short paths");
        expect<std::out_of_range>([&]{t.pathBetween(2,99);},"Missing key");
        PathTree chain; chain.insert(1); chain.insert(2); chain.insert(3);
        check(!chain.isHeightBalanced() && chain.diameter()==3,"chain");
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
