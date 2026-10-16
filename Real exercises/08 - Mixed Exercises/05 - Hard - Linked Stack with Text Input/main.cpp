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
        TextStack s;std::istringstream in("4\n7\n");loadNumbers(in,s);check(s.pop()==7 && s.pop()==4 && s.empty(),"load order");
        expect<std::runtime_error>([&]{std::istringstream bad("9\nbad\n");loadNumbers(bad,s);},"Invalid line");check(s.pop()==9,"earlier input retained");

        { TextStack a;check(a.empty(),"new empty");
          expect<std::runtime_error>([&]{a.pop();},"Stack is empty");
          for(int x:{INT_MIN,0,INT_MAX})a.push(x);
          check(a.pop()==INT_MAX && a.pop()==0 && a.pop()==INT_MIN && a.empty(),"LIFO and extremes");
          a.push(7);check(a.pop()==7 && a.empty(),"reuse after draining"); }
        { TextStack a;std::istringstream input;loadNumbers(input,a);check(a.empty(),"empty input");
          std::istringstream valid("  -3 \n\t0\t\n+4");loadNumbers(valid,a);
          check(a.pop()==4 && a.pop()==0 && a.pop()==-3 && a.empty(),"whitespace and no final newline"); }
        for(const std::string line:{"","   ","1 2","3x","2.5","-","999999999999999999999999999"}){
          TextStack a;a.push(99);std::istringstream input("8\n"+line+"\n77\n");
          expect<std::runtime_error>([&]{loadNumbers(input,a);},"Invalid line");
          check(a.pop()==8 && a.pop()==99 && a.empty(),"invalid line not pushed; later line not processed");
        }
        { TextStack a;std::istringstream input("1\n2\nbad\n");
          expect<std::runtime_error>([&]{loadNumbers(input,a);},"Invalid line");
          // Leaves nodes for the destructor to release after parser failure.
        }

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
