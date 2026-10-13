#include "exercise.hpp"

// Public smoke checks, not an exhaustive grading suite. Add your own cases.
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
        Matrix a(2,3);
        for(int r=0;r<2;++r) for(int c=0;c<3;++c) a.at(r,c)=r*3+c+1;
        Matrix b(a); b.at(0,0)=99; check(a.at(0,0)==1,"copy independence");
        a.resize(3,2); check(a.at(1,0)==4 && a.at(1,1)==5 && a.at(2,1)==0,"rectangular overlap");
        Matrix c(0,0); c=a; c.at(0,1)=77; check(a.at(0,1)==2,"assignment independence");
        c=c; check(c.at(0,1)==77,"self-assignment");
        expect<std::out_of_range>([&]{a.at(1,2);},"Cell out of range");
        expect<std::invalid_argument>([&]{a.resize(-1,2);},"Negative dimension");
        check(a.rows()==3 && a.cols()==2,"failed resize preserves shape");
        std::cout << "Public checks passed. Add the edge cases from README.md.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unexpected uncaught custom exception.\n";
        return 1;
    }
}
