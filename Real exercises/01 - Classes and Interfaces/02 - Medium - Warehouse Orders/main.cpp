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
        StockItem x("pen",10);
        check(x.reserve(4) && x.available()==6 && x.reserved()==4, "reservation");
        check(!x.dispatch(5) && x.dispatch(3), "dispatch limit");
        check(x.available()==6 && x.reserved()==1, "dispatch accounting");
        Warehouse w;
        check(w.addItem("pen",10) && !w.addItem("pen",20), "unique SKU");
        check(w.addItem("book",5) && w.reserve("pen",4), "warehouse reservation");
        check(w.release("pen",1) && w.dispatch("pen",2), "stock updates");
        check(!w.reserve("missing",1), "missing item");
        check(w.report()=="pen 7/1\nbook 5/0\n", "report");
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
