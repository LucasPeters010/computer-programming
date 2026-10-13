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
        ServiceQueue q(3); q.add(1,"Printer"); q.add(2,"Login"); q.add(3,"WiFi");
        expect<std::runtime_error>([&]{q.add(4,"Laptop");},"Queue is full");
        check(q.cancel(2) && !q.cancel(99),"middle cancellation");
        q.add(4,"Laptop"); check(q.listing()=="#1 Printer\n#3 WiFi\n#4 Laptop\n","queue order");
        check(q.serve()=="#1 Printer" && q.cancel(4),"serve and remove tail");
        q.add(2,"Login again"); check(q.size()==2,"reuse space and ID");
        expect<std::runtime_error>([&]{q.add(2,"Duplicate");},"Duplicate request");
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
