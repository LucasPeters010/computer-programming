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
        SearchTree t;for(int x:std::vector<int>({6,2,8,1,4,2}))t.insert(x);
        check(t.contains(4) && !t.contains(7),"membership");check(t.inOrder()==std::vector<int>({1,2,4,6,8}),"order and duplicates");

        { SearchTree a;check(!a.contains(0) && a.inOrder().empty(),"empty queries");
          a.insert(0);check(a.contains(0) && !a.contains(-1) && !a.contains(1),"root and absent neighbours");
          a.insert(0);check(a.inOrder()==std::vector<int>{0},"duplicate root"); }
        { SearchTree a,b;std::vector<int> asc,desc;
          for(int i=1;i<=25;++i){a.insert(i);b.insert(-i);asc.push_back(i);}
          for(int i=-25;i<0;++i)desc.push_back(i);
          check(a.inOrder()==asc && b.inOrder()==desc,"both skew directions");
          for(int i=1;i<=25;++i)check(a.contains(i) && b.contains(-i),"deep membership");
          check(!a.contains(26) && !b.contains(-26),"absent beyond leaves"); }
        { SearchTree a;for(int x:{0,INT_MIN,INT_MAX,-1,1,INT_MIN})a.insert(x);
          check(a.inOrder()==std::vector<int>({INT_MIN,-1,0,1,INT_MAX}),"extremes and duplicates");
          check(a.contains(INT_MIN) && a.contains(INT_MAX),"extreme membership"); }

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
