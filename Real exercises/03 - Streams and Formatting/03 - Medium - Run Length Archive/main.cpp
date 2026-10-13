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
        std::istringstream raw("AA  B\n"); std::ostringstream archive;
        encodeRuns(raw,archive);
        check(archive.str()=="2:65\n2:32\n1:66\n1:10\n", "encoding including whitespace");
        std::istringstream encoded(archive.str()); std::ostringstream decoded;
        decodeRuns(encoded,decoded); check(decoded.str()=="AA  B\n", "round trip");
        std::ostringstream preserved; preserved << "existing";
        expect<std::runtime_error>([&]{std::istringstream bad("2:65\n0:66\n"); decodeRuns(bad,preserved);}, "Invalid archive");
        check(preserved.str()=="existing", "atomic decode output");
        expect<std::runtime_error>([]{std::istringstream bad("1:256"); std::ostringstream o; decodeRuns(bad,o);}, "Invalid archive");
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
