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
        Polynomial p; p.addTerm(3,2); p.addTerm(4,0); p.addTerm(-1,2);
        check(p.terms()=="2@2 4@0" && p.evaluate(3)==22,"merged terms");
        Polynomial q; q.addTerm(-2,2); q.addTerm(5,1); p.addFrom(q);
        check(p.terms()=="5@1 4@0" && q.terms()=="-2@2 5@1","addition and cancellation");
        p.addFrom(p); check(p.terms()=="10@1 8@0","self addition");
        expect<std::runtime_error>([&]{std::istringstream in("7 3\nbad\n"); p.load(in);},"Malformed term");
        check(p.terms()=="10@1 8@0","atomic load");
        std::istringstream in("1 2\n-1 2\n3 0\n"); p.load(in); check(p.terms()=="3@0","replacement");
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
