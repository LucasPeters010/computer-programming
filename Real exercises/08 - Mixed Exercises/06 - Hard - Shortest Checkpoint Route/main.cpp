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
        RouteMap m({"...","...","..."});
        check(m.shortestVia(1,1)==std::vector<std::string>({"0,0","0,1","1,1","1,2","2,2"}),"shortest route and tie order");
        check(m.shortestVia(0,0)==std::vector<std::string>({"0,0","0,1","0,2","1,2","2,2"}),"checkpoint at start");
        RouteMap blocked({".#","#."}); check(blocked.shortestVia(0,0).empty(),"unreachable");
        expect<std::out_of_range>([&]{m.shortestVia(3,0);},"Invalid checkpoint");
        expect<std::invalid_argument>([]{RouteMap bad({"..","."});},"Invalid grid");
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
