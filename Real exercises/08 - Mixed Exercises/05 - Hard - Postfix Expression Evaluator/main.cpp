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
        ValueStack s; for(int i=0;i<20;++i) s.push(i+0.5);
        check(close(s.pop(),19.5) && s.size()==19,"growth");
        check(close(evaluatePostfix("8 2 / 3 +"),7),"operand order");
        check(close(evaluatePostfix("-2 3 * 1.5 +"),-4.5),"signed decimals");
        expect<std::runtime_error>([]{evaluatePostfix("1 +");},"Missing operand");
        expect<std::runtime_error>([]{evaluatePostfix("4 0 /");},"Division by zero");
        expect<std::runtime_error>([]{evaluatePostfix("3x");},"Invalid token");
        expect<std::runtime_error>([]{evaluatePostfix("1 2");},"Incomplete expression");
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
