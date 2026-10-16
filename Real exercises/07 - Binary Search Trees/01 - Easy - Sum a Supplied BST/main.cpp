#include "exercise.hpp"

// Original examples plus automatic boundary/error checks. Implement solution.cpp.
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
        Tree t;check(t.sum()==0,"empty");t.insert(4);t.insert(2);t.insert(8);t.insert(2);check(t.sum()==14,"sum with duplicate ignored");

        { Tree a; a.insert(-7); check(a.sum()==-7,"singleton negative");
          a.insert(-7); check(a.sum()==-7,"duplicate singleton"); }
        { Tree a; for(int x:{0,-5,8,-2}) a.insert(x);
          check(a.sum()==1 && a.sum()==1,"mixed signs and repeated query"); }
        { Tree a,b; for(int i=1;i<=30;++i){a.insert(i);b.insert(-i);}
          check(a.sum()==465 && b.sum()==-465,"both skew directions"); }
        { Tree a; a.insert(INT_MAX);a.insert(INT_MAX-1);
          check(a.sum()==2LL*INT_MAX-1,"sum exceeds int"); }
        { Tree a; a.insert(INT_MIN);a.insert(-1);
          check(a.sum()==static_cast<long long>(INT_MIN)-1,"negative sum exceeds int"); }

        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unexpected uncaught custom exception.\n";
        return 1;
    }
}
