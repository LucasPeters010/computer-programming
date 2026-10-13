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
        StudentRecord s(7);
        check(s.addGrade(4.5,30) && s.addGrade(7,70), "grades accepted");
        check(close(s.average(),6.25) && s.passed(), "weighted average");
        check(!s.addGrade(10,1) && close(s.average(),6.25), "no overweight mutation");
        Gradebook g;
        check(g.enroll(9) && g.enroll(2) && g.enroll(4), "enrollment");
        check(!g.enroll(9) && !g.record(99,8,100), "IDs");
        check(g.record(9,7,100) && g.record(2,6,100) && g.record(4,10,30), "recording");
        check(g.passedIds()==std::vector<int>({2,9}), "only completed passes");
        check(close(g.cohortAverage(),6.5), "cohort average");
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
