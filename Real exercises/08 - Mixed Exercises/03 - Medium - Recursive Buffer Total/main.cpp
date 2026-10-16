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
        NumberArray a(3);a.at(0)=5;a.at(1)=-2;a.at(2)=8;check(a.total()==11,"recursive total");NumberArray empty(0);check(empty.total()==0,"empty");

        { NumberArray a(0);check(a.total()==0,"empty total");
          for(int x:{-1,0,1})expect<std::out_of_range>([&]{a.at(x);},"Invalid index"); }
        { NumberArray a(1);check(a.at(0)==0 && a.total()==0,"singleton initialized");
          a.at(0)=-9;check(a.total()==-9,"singleton negative");
          int& ref=a.at(0);ref=7;check(a.total()==7,"writable reference");
          for(int x:{-1,1,INT_MAX})expect<std::out_of_range>([&]{a.at(x);},"Invalid index");
          check(a.total()==7,"bad access leaves data unchanged"); }
        { NumberArray a(30);check(a.total()==0,"all zero initialized");
          int expected=0;for(int i=0;i<30;++i){check(a.at(i)==0,"each element initialized");a.at(i)=i-15;expected+=i-15;}
          check(a.total()==expected && a.total()==expected,"mixed signs repeated total"); }

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
