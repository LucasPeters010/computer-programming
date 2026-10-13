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
        StockTree t; t.add(7,5); t.add(2,8); t.add(7,2); t.sell(2,3);
        check(t.stock(7)==7 && t.totalStock()==12,"stock operations");
        check(t.lowStock(7)==std::vector<int>({2}),"strict low-stock threshold");
        expect<std::runtime_error>([&]{t.sell(7,8);},"Insufficient stock");
        check(t.stock(7)==7,"failed sale unchanged");
        std::istringstream in("ADD 7 5\nADD 2 8\nSELL 7 2\nGET 7\nLOW 5\nSELL 2 9\nADD 1 2 extra\nTOTAL\nLIST\n");
        std::ostringstream out; runStockSession(in,out);
        check(out.str()=="3\n7\nERROR: Insufficient stock\nERROR: Invalid command\n11\n2 8\n7 3\n","complete command session");
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
