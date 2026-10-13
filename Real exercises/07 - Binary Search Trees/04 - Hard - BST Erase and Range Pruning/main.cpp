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
        MutableTree t;
        for(int x:std::vector<int>({8,4,12,2,6,10,14,9,11})) t.insert(x);
        check(t.erase(8) && !t.erase(99),"two-child root and missing key");
        check(t.inOrder()==std::vector<int>({2,4,6,9,10,11,12,14}) && t.size()==8,"after erase");
        check(t.retainRange(6,11)==4,"pruned count");
        check(t.inOrder()==std::vector<int>({6,9,10,11}) && t.size()==4,"retained keys");
        check(t.retainRange(9,1)==4 && t.height()==0,"clear inverted range");
        t.insert(5); check(t.erase(5) && t.size()==0,"reuse and singleton deletion");
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
