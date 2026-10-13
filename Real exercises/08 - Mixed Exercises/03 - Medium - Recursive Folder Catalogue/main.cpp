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
        Catalogue c; int notes=c.addFolder(0,"notes"); int cpp=c.addFolder(notes,"cpp");
        c.addFile(0,"readme",10); c.addFile(notes,"week1",20); c.addFile(cpp,"stack",30);
        check(c.totalBytes(0)==60 && c.totalBytes(notes)==50,"recursive sizes");
        check(c.outline(0)=="root/\n  readme 10\n  notes/\n    week1 20\n    cpp/\n      stack 30\n","hierarchy formatting");
        expect<std::invalid_argument>([&]{c.addFolder(0,"notes");},"Invalid folder name");
        expect<std::out_of_range>([&]{c.totalBytes(99);},"Unknown folder");
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
