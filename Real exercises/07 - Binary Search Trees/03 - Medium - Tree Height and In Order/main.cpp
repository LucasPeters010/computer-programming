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
        Tree t;check(t.height()==0 && t.inOrder().empty(),"empty");for(int x:std::vector<int>({8,4,6,1,5}))t.insert(x);
        check(t.height()==4 && t.inOrder()==std::vector<int>({1,4,5,6,8}),"height and order");

        { Tree a;a.insert(-4);a.insert(-4);
          check(a.height()==1 && a.inOrder()==std::vector<int>{-4},"singleton and duplicate"); }
        { Tree a,b;std::vector<int> asc,desc;
          for(int i=1;i<=20;++i){a.insert(i);b.insert(-i);asc.push_back(i);}
          for(int i=-20;i<0;++i)desc.push_back(i);
          check(a.height()==20 && b.height()==20,"both skew heights");
          check(a.inOrder()==asc && b.inOrder()==desc,"both skew traversals");
          check(a.inOrder()==asc,"repeated traversal"); }
        { Tree a;for(int x:{4,2,6,1,3,5,7})a.insert(x);
          check(a.height()==3 && a.inOrder()==std::vector<int>({1,2,3,4,5,6,7}),"balanced");
          a.insert(1);a.insert(4);check(a.height()==3 && a.inOrder().size()==7,"duplicates ignored"); }

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
