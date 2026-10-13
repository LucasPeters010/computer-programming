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
        std::istringstream ok(" 2.5 4 3 \n");
        check(close(volume(ok),30), "volume");
        expect<std::runtime_error>([]{std::istringstream in("2 3"); volume(in);}, "Malformed measurement input");
        expect<std::runtime_error>([]{std::istringstream in("2 3 4 extra"); volume(in);}, "Malformed measurement input");
        expect<std::invalid_argument>([]{std::istringstream in("2 0 4"); volume(in);}, "Dimensions must be positive");
        expect<std::runtime_error>([]{std::istringstream in("-2 3 4 extra"); volume(in);}, "Malformed measurement input");
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
