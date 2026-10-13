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
        SequenceEditor e; e.insert(0,4); e.insert(1,7); e.resize(4);
        check(e.toString()=="[4,7,0,0]","resize growth"); e.undo();
        check(e.toString()=="[4,7]" && !e.hasUndo(),"consume undo");
        std::istringstream batch("INSERT 1 9\nERASE 0\nRESIZE 4\n"); e.applyBatch(batch);
        check(e.toString()=="[9,7,0,0]","batch result"); e.undo();
        check(e.toString()=="[4,7]","batch is one undo step");
        e.insert(2,8);
        expect<std::out_of_range>([&]{std::istringstream bad("INSERT 0 1\nERASE 99\n"); e.applyBatch(bad);},"Index out of range");
        check(e.toString()=="[4,7,8]" && e.hasUndo(),"batch preserves current state");
        e.undo(); check(e.toString()=="[4,7]","batch preserves previous undo snapshot");
        expect<std::runtime_error>([&]{e.undo();},"Nothing to undo");
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
