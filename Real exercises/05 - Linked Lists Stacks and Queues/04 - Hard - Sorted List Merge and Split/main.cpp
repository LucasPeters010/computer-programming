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
        SortedList a,b,high;
        for(int x:std::vector<int>({4,1,4})) a.insert(x);
        for(int x:std::vector<int>({5,2,4})) b.insert(x);
        a.mergeFrom(b);
        check(a.toVector()==std::vector<int>({1,2,4,4,4,5}) && b.size()==0,"sorted merge");
        a.splitAt(4,high);
        check(a.toVector()==std::vector<int>({1,2}) && high.toVector()==std::vector<int>({4,4,4,5}),"split boundary");
        expect<std::invalid_argument>([&]{a.splitAt(1,high);},"Invalid destination");
        a.mergeFrom(a); check(a.size()==2,"self merge");
        b.insert(8); check(b.size()==1,"source reuse");
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
