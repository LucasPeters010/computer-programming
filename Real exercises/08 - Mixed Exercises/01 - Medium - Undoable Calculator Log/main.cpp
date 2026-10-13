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
        Calculator c; c.execute("ADD 5"); c.execute("MUL 3"); c.execute("UNDO");
        check(c.value()==5 && c.execute("PRINT")=="5","history");
        expect<std::runtime_error>([&]{c.execute("ADD 2 extra");},"Invalid command");
        check(c.value()==5,"invalid command unchanged");
        std::istringstream in("ADD 4\nMUL 2\nPRINT\nUNDO\nPRINT\nUNDO\nUNDO\nPRINT\n");
        std::ostringstream out; runCalculator(in,out);
        check(out.str()=="8\n4\nERROR: Nothing to undo\n0\n","command session");
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
