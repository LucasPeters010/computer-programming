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
        SeatRow row(5);
        check(row.reserve(8,2)==0 && row.reserve(9,2)==2, "leftmost blocks");
        check(row.cancel(8)==2 && row.reserve(10,3)==-1, "fragmentation");
        check(row.layout()=="0 0 9 9 0" && row.occupied()==2, "failed booking unchanged");
        Train t(2,4);
        check(t.book(1,3)==0 && t.book(2,2)==1, "first fitting row");
        check(t.book(1,1)==-1 && t.book(3,5)==-1, "reject duplicate or too large");
        check(t.cancel(1)==3 && t.book(3,4)==0, "reuse cancelled seats");
        check(t.layout()=="3 3 3 3\n2 2 0 0\n", "train layout");
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
