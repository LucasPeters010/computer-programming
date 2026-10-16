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
        std::istringstream in("PUSH 4\nPUSH 7\nPUSH 9\nTOP\nPOP\nSIZE\nPUSH 5 extra\nPOP\nPOP\n");std::ostringstream out;runStack(in,out,2);
        check(out.str()=="Error: Stack is full\n7\n7\n1\nError: Invalid command\n4\nError: Stack is empty\n","exam session");

        { ExamStack a(0);check(a.size()==0,"zero capacity");
          expect<std::runtime_error>([&]{a.push(1);},"Stack is full");
          expect<std::runtime_error>([&]{a.top();},"Stack is empty");
          expect<std::runtime_error>([&]{a.pop();},"Stack is empty");
          check(a.size()==0,"zero capacity unchanged"); }
        { ExamStack a(2);a.push(INT_MIN);a.push(INT_MAX);
          check(a.top()==INT_MAX && a.top()==INT_MAX && a.size()==2,"top does not pop");
          expect<std::runtime_error>([&]{a.push(0);},"Stack is full");
          check(a.size()==2 && a.pop()==INT_MAX,"full push preserves top");
          a.push(-3);check(a.pop()==-3 && a.pop()==INT_MIN && a.size()==0,"reuse after pop");
          expect<std::runtime_error>([&]{a.pop();},"Stack is empty");
          a.push(8);check(a.top()==8 && a.size()==1,"reuse after empty error"); }
        { std::istringstream input("PUSH 4\nPUSH 5 extra\nTOP extra\nPOP extra\nSIZE extra\nPUSH\nPUSH 2.5\nPUSH x\n\nWHAT\nTOP\nSIZE\nPOP\nTOP\nPUSH -8\nTOP");
          std::ostringstream output;runStack(input,output,1);
          std::string expected;for(int i=0;i<9;++i)expected+="Error: Invalid command\n";
          expected+="4\n1\n4\nError: Stack is empty\n-8\n";
          check(output.str()==expected,"parse before mutation, syntax before capacity, recovery"); }
        { std::istringstream input(" SIZE \nPUSH 1\nPOP\nTOP\nSIZE");std::ostringstream output;runStack(input,output,0);
          check(output.str()=="0\nError: Stack is full\nError: Stack is empty\nError: Stack is empty\n0\n","zero capacity session"); }
        { std::istringstream input("PUSH 99999999999999999999999\nSIZE\n PUSH +7 \n TOP \n");std::ostringstream output;runStack(input,output,1);
          check(output.str()=="Error: Invalid command\n0\n7\n","overflow and surrounding whitespace"); }
        { std::istringstream input;std::ostringstream output;runStack(input,output,2);check(output.str().empty(),"empty session"); }

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
