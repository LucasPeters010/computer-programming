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
        check(secondDistinctMinimum({7,2,2,9,4})==4, "distinct ordering");
        check(secondDistinctMinimum({-1,-5,-1})==-1, "negative values");
        check(secondDistinctMinimum({INT_MAX,INT_MIN})==INT_MAX, "full int range");
        bool few=false;
        try { secondDistinctMinimum({8}); } catch(const TooFewValues& e) { few=e.count()==1; }
        check(few,"TooFewValues payload");
        bool equal=false;
        try { secondDistinctMinimum({6,6,6}); } catch(const NoDistinctValue& e) { equal=e.value()==6; }
        check(equal,"NoDistinctValue payload");
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
