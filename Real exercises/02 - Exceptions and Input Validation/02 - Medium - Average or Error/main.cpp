#include "exercise.hpp"

// Examples and automatic edge-case checks; run with solution.cpp.
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
        check(close(checkedAverage({60,81}),70.5),"average");
        expect<std::runtime_error>([]{checkedAverage({});},"No scores");
        bool caught=false; try{checkedAverage({80,-1,120});}catch(const InvalidScore& e){caught=e.position()==1;}
        check(caught,"first invalid score");

        for (int value : {0, 1, 100}) {
            check(close(checkedAverage({value}), value), "singleton boundary");
        }
        check(close(checkedAverage({0,100}),50.0), "both boundaries");
        check(close(checkedAverage({0,1,1}),2.0/3.0), "fractional average");
        check(close(checkedAverage(std::vector<int>(1000,100)),100), "long valid input");
        const std::vector<std::vector<int>> badCases = {
            {-1}, {101}, {INT_MIN}, {INT_MAX}, {-1,50,101},
            {50,101,-1}, {0,100,-1}, {0,100,101}
        };
        const std::vector<int> positions = {0,0,0,0,0,1,2,2};
        for (std::size_t i=0; i<badCases.size(); ++i) {
            std::vector<int> values = badCases.at(i);
            bool invalid = false;
            try { checkedAverage(values); }
            catch (const InvalidScore& e) {
                invalid = true;
                check(e.position()==positions.at(i), "first invalid index case " + std::to_string(i));
            }
            check(invalid, "InvalidScore required case " + std::to_string(i));
            check(values==badCases.at(i), "invalid input unchanged");
        }
        std::vector<int> values = {100,0,25,75};
        const std::vector<int> before = values;
        check(close(checkedAverage(values),50), "valid unsorted input");
        check(values==before, "valid input unchanged");
        check(InvalidScore(17).position()==17, "exception stores supplied index");
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
