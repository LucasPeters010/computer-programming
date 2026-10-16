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
        Tree t;check(t.leafCount()==0,"empty");for(int x:std::vector<int>({8,4,12,2,6}))t.insert(x);
        check(t.leafCount()==3 && t.countBetween(4,8)==3,"summaries");check(t.countBetween(8,4)==0,"inverted range");

        { Tree a; check(a.countBetween(INT_MIN,INT_MAX)==0,"empty range");
          a.insert(0);check(a.leafCount()==1,"singleton leaf");
          check(a.countBetween(0,0)==1 && a.countBetween(1,5)==0,"singleton endpoints");
          a.insert(0);check(a.leafCount()==1,"duplicate leaf"); }
        { Tree a,b; for(int i=0;i<20;++i){a.insert(i);b.insert(-i);}
          check(a.leafCount()==1 && b.leafCount()==1,"one-child nodes are not leaves");
          check(a.countBetween(0,19)==20 && a.countBetween(4,7)==4,"inclusive range");
          check(a.countBetween(7,4)==0 && a.countBetween(25,30)==0,"inverted and disjoint"); }
        { Tree a;for(int x:{0,-2,2,INT_MIN,INT_MAX})a.insert(x);
          check(a.leafCount()==2,"asymmetric leaves");
          check(a.countBetween(INT_MIN,INT_MAX)==5,"extreme range");
          check(a.countBetween(INT_MIN,INT_MIN)==1 && a.countBetween(INT_MAX,INT_MAX)==1,"extreme equality"); }

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
