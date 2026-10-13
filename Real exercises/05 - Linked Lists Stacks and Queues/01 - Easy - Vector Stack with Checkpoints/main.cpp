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
        CheckpointStack s; s.push(4); s.push(7); int m=s.mark();
        s.push(9); s.push(2); check(s.toString()=="[2,9,7,4]","stack order");
        s.rollback(m); check(s.top()==7 && s.pop()==7 && s.size()==1,"rollback");
        expect<std::out_of_range>([&]{s.rollback(m);},"Invalid checkpoint");
        s.rollback(0); check(s.isEmpty() && s.toString()=="[]","empty stack");
        expect<std::runtime_error>([&]{s.pop();},"Stack is empty");
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
