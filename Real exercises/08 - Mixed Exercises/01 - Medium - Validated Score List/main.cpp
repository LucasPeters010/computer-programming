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
        ScoreList s;expect<std::runtime_error>([&]{s.average();},"No scores");s.add(40);s.add(81);
        expect<std::out_of_range>([&]{s.add(101);},"Invalid score");check(close(s.average(),60.5) && s.passingCount()==1,"valid state");

        { ScoreList a;check(a.passingCount()==0,"empty passing count");
          for(int x:{-1,101,INT_MIN,INT_MAX})expect<std::out_of_range>([&]{a.add(x);},"Invalid score");
          expect<std::runtime_error>([&]{a.average();},"No scores");
          a.add(0);a.add(54);a.add(55);a.add(100);
          check(close(a.average(),52.25) && a.passingCount()==2,"score endpoints and threshold");
          expect<std::out_of_range>([&]{a.add(-1);},"Invalid score");
          check(close(a.average(),52.25) && a.passingCount()==2,"rejection preserves data");
          a.add(55);check(close(a.average(),52.8) && a.passingCount()==3,"duplicate scores retained"); }
        { ScoreList a;a.add(1);a.add(2);check(close(a.average(),1.5),"fractional average"); }

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
