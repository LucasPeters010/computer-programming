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
        LinkedQueue a,b; a.push(1); a.push(2); a.push(3); b.push(9);
        check(a.transferTo(b,2)==2,"moved count");
        check(a.toVector()==std::vector<int>({3}) && b.toVector()==std::vector<int>({9,1,2}),"transfer order");
        check(a.transferTo(b,20)==1 && a.size()==0,"whole queue transfer");
        a.push(7); check(a.front()==7 && a.pop()==7,"reuse emptied queue");
        check(b.transferTo(b,2)==0 && b.size()==4,"self transfer");
        expect<std::invalid_argument>([&]{b.transferTo(a,-1);},"Negative count");
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
