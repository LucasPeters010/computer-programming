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
        check(parseRecord("a,,b,")==std::vector<std::string>({"a","","b",""}), "empty fields");
        check(parseRecord("\"red,blue\",\"say \"\"hi\"\"\"")==std::vector<std::string>({"red,blue","say \"hi\""}), "quotes and commas");
        std::vector<std::string> fields={"plain","x,y","a\"b",""};
        std::ostringstream out; writeRecord(fields,out);
        check(out.str()=="plain,\"x,y\",\"a\"\"b\",", "canonical serialization");
        check(parseRecord(out.str())==fields, "round trip");
        expect<std::runtime_error>([]{parseRecord("\"a\" x");}, "Malformed record");
        expect<std::runtime_error>([]{parseRecord("a\"b");}, "Malformed record");
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
