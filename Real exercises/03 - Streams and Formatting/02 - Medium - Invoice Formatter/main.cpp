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
        std::istringstream in("Apples;3;150\nBad;0;20\nMilk;2;125\n");
        std::ostringstream out;
        check(formatInvoice(in,out)==1, "rejected invoice row");
        std::ostringstream expected;
        expected << std::left << std::setw(12) << "Apples" << ' ' << std::right << std::setw(3) << 3 << ' ' << std::setw(8) << "4.50" << '\n';
        expected << std::left << std::setw(12) << "Milk" << ' ' << std::right << std::setw(3) << 2 << ' ' << std::setw(8) << "2.50" << '\n';
        expected << "TOTAL 7.00\n";
        check(out.str()==expected.str(), "alignment and cents");
        std::istringstream empty; std::ostringstream zero;
        check(formatInvoice(empty,zero)==0 && zero.str()=="TOTAL 0.00\n", "empty invoice");
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
