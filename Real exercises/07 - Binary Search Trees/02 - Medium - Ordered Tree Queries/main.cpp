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
        OrderedTree t;
        for(int x:std::vector<int>({8,4,6,1,5})) t.insert(x);
        check(t.inOrder()==std::vector<int>({1,4,5,6,8}) && t.height()==4,"order and height");
        check(t.kthSmallest(2)==5 && t.floorKey(7)==6 && t.ceilingKey(7)==8,"queries");
        check(t.floorKey(4)==4 && t.ceilingKey(4)==4,"exact match");
        expect<std::out_of_range>([&]{t.kthSmallest(5);},"Invalid rank");
        expect<std::out_of_range>([&]{t.floorKey(0);},"No floor");
        expect<std::out_of_range>([&]{t.ceilingKey(9);},"No ceiling");
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
