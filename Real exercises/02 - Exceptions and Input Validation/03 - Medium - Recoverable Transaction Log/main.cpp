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
        check(applyTransaction(100,"WITHDRAW 30",1)==70, "valid transaction");
        std::istringstream in("DEPOSIT 100\nWITHDRAW 150\nDEPOSIT -2\nDEPOSIT 20 extra\nWITHDRAW 25\n");
        std::ostringstream errors;
        check(processLog(in,errors)==75, "continue without changing balance on errors");
        check(errors.str()=="2: Insufficient funds\n3: Amount must be positive\n4: Malformed transaction\n", "line diagnostics");
        bool caught=false;
        try { applyTransaction(0,"",8); } catch(const TransactionError& e) { caught=e.line()==8 && e.message()=="Malformed transaction"; }
        check(caught,"blank line error");
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
