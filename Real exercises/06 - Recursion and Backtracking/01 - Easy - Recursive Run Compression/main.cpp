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
        check(compressRuns({4,4,-1,-1,-1,4})==std::vector<std::string>({"4:2","-1:3","4:1"}),"run boundaries");
        check(longestRun({4,4,-1,-1,-1,4})==3,"longest run");
        check(compressRuns({}).empty() && longestRun({})==0,"empty input");
        check(compressRuns({8})==std::vector<std::string>({"8:1"}) && longestRun({8})==1,"single value");
        check(longestRun({1,2,3})==1,"all different");
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
