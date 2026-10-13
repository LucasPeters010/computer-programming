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
        ScoreStore s;
        std::istringstream first("3 70\n1 90\n"); s.importScores(first);
        check(s.report()=="1 90\n3 70\n", "sorted report");
        bool rejected=false;
        try { std::istringstream bad("2 80\n3 60\n"); s.importScores(bad); }
        catch(const ImportError& e) { rejected=e.line()==2 && e.message()=="Duplicate ID"; }
        check(rejected && s.size()==2 && s.report()=="1 90\n3 70\n", "atomic rejection");
        expect<std::out_of_range>([&]{s.scoreFor(2);}, "Unknown ID");
        std::istringstream next("2 80\n"); s.importScores(next);
        check(s.size()==3 && s.scoreFor(2)==80, "later import succeeds");
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
