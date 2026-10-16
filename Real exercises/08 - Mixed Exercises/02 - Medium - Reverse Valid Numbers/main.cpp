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
        std::istringstream in("3 8 -2");check(reverseNumbers(in)=="-2 8 3","reverse");std::istringstream empty;check(reverseNumbers(empty).empty(),"empty");
        expect<std::runtime_error>([]{std::istringstream bad("2 nope");reverseNumbers(bad);},"Invalid number");

        for(const std::string text:{""," \t\n ","42"," 1\t-2\n0 1 \n"}){
            std::istringstream input(text);
            const std::string expected = text=="42" ? "42" : text==" 1\t-2\n0 1 \n" ? "1 0 -2 1" : "";
            check(reverseNumbers(input)==expected,"empty/single/whitespace/duplicates: "+text);
        }
        for(const std::string text:{"bad","1 bad 2","2x","1 2.5","-","+","999999999999999999999999999999"}){
            expect<std::runtime_error>([&]{std::istringstream input(text);reverseNumbers(input);},"Invalid number");
        }
        { std::string text=std::to_string(INT_MIN)+" "+std::to_string(INT_MAX);
          std::istringstream input(text);
          check(reverseNumbers(input)==std::to_string(INT_MAX)+" "+std::to_string(INT_MIN),"int endpoints"); }

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
