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
        ExamTree t;check(t.height()==0,"empty");t.insert(5);t.insert(2);t.insert(7);check(t.contains(2) && !t.contains(9),"membership");
        std::istringstream in("8 4 6 1 5 4");std::ostringstream out;treeSummary(in,out);check(out.str()=="1 4 5 6 8\nHeight: 4\n","summary");

        { ExamTree a;check(a.height()==0 && a.inOrder().empty() && !a.contains(0),"empty queries");
          a.insert(0);a.insert(0);check(a.height()==1 && a.inOrder()==std::vector<int>{0},"singleton duplicate");
          check(a.contains(0) && !a.contains(1) && !a.contains(-1),"root and absent neighbours"); }
        { ExamTree a,b;std::vector<int> asc,desc;
          for(int i=1;i<=25;++i){a.insert(i);b.insert(-i);asc.push_back(i);}
          for(int i=-25;i<0;++i)desc.push_back(i);
          check(a.height()==25 && b.height()==25,"both skew heights");
          check(a.inOrder()==asc && b.inOrder()==desc,"skew traversals");
          check(a.contains(25) && b.contains(-25) && !a.contains(26),"deep search"); }
        { ExamTree a;for(int x:{4,2,6,1,3,5,7,4,1})a.insert(x);
          check(a.height()==3 && a.inOrder()==std::vector<int>({1,2,3,4,5,6,7}),"balanced and duplicates");
          check(a.inOrder()==std::vector<int>({1,2,3,4,5,6,7}),"repeat query"); }
        { ExamTree a;for(int x:{0,INT_MIN,INT_MAX})a.insert(x);
          check(a.contains(INT_MIN) && a.contains(INT_MAX) && a.height()==2,"int extremes"); }
        for(const auto& item:std::vector<std::vector<std::string>>{
            {"","\nHeight: 0\n"},{" \n\t","\nHeight: 0\n"},{"-7 -7","-7\nHeight: 1\n"},
            {"1 2 3 4","1 2 3 4\nHeight: 4\n"},{"4 3 2 1","1 2 3 4\nHeight: 4\n"},
            {"0 -2 2 -3 -1 1 3","-3 -2 -1 0 1 2 3\nHeight: 3\n"}}){
          std::istringstream input(item[0]);std::ostringstream output;treeSummary(input,output);
          check(output.str()==item[1],"exact summary: "+item[0]); }

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
