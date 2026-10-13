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
        std::istringstream in("Lucas 60 80 100\nMila 50 nope\nJo 75\nEmpty\n");
        std::ostringstream out;
        check(summarizeScores(in,out)==2, "rejected count");
        check(out.str()=="Lucas: count=3 average=80.00\nJo: count=1 average=75.00\n", "formatted output");
        std::istringstream blank("\nA 100x\nB -1\n"); std::ostringstream unused;
        check(summarizeScores(blank,unused)==3 && unused.str().empty(), "whole-line validation");
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
