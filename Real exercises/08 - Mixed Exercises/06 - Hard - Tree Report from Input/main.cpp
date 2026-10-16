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
        std::istringstream in("5 2 8 2");std::ostringstream out;writeTreeReport(in,out);check(out.str()=="2 5 8\nSum: 15\n","report");
        std::istringstream empty;std::ostringstream zero;writeTreeReport(empty,zero);check(zero.str()=="\nSum: 0\n","empty report");

        { ReportTree a;check(a.sum()==0 && a.inOrder().empty(),"empty direct queries");
          for(int x:{0,-3,5,-3})a.insert(x);
          check(a.sum()==2 && a.inOrder()==std::vector<int>({-3,0,5}),"negative and duplicate direct queries");
          check(a.inOrder()==std::vector<int>({-3,0,5}),"repeated traversal"); }
        for(const auto& item:std::vector<std::vector<std::string>>{
            {" \t\n","\nSum: 0\n"},{"7 7 7","7\nSum: 7\n"},
            {"-2 0 -5 -2","-5 -2 0\nSum: -7\n"},
            {"1 2 3 4","1 2 3 4\nSum: 10\n"},{"4 3 2 1\n","1 2 3 4\nSum: 10\n"}}){
          std::istringstream input(item[0]);std::ostringstream output;writeTreeReport(input,output);
          check(output.str()==item[1],"exact report: "+item[0]); }
        { std::istringstream input(std::to_string(INT_MAX)+" "+std::to_string(INT_MAX-1));std::ostringstream output;
          writeTreeReport(input,output);check(output.str()==std::to_string(INT_MAX-1)+" "+std::to_string(INT_MAX)+"\nSum: "+std::to_string(2LL*INT_MAX-1)+"\n","wide report sum"); }

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
