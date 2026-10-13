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
        SummaryTree t;
        check(t.sum()==0 && t.leafCount()==0,"empty tree");
        for(int x:std::vector<int>({8,3,10,1,6,14,4,7})) check(t.insert(x),"new key");
        check(!t.insert(6) && t.contains(7) && !t.contains(9),"membership and duplicates");
        check(t.sum()==53 && t.leafCount()==4,"tree summaries");
        check(t.rangeSum(4,10)==35 && t.rangeSum(10,4)==0,"inclusive range");
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
