#include "exercise.hpp"

// Examples and automatic edge-case checks; run with solution.cpp.
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
        std::istringstream in("80\nno\n101\n60 extra\n70\n");std::ostringstream errors;
        check(collectScores(in,errors)==std::vector<int>({80,70}),"valid scores survive");
        check(errors.str()=="Bad input\nBad score\nBad input\n","error messages");

        check(readScore("0")==0 && readScore("100")==100, "inclusive boundaries");
        check(readScore(" \t42\r ")==42, "surrounding whitespace");
        check(readScore("+7")==7 && readScore("007")==7, "valid integer forms");
        check(readScore("-0")==0, "negative zero");
        const std::vector<std::string> malformed = {
            "", " ", "\t\r", "abc", "3.5", "3abc", "1 2", "+", "--2",
            "101 extra", "-1 extra", "101.5", "1e2",
            "99999999999999999999999999999",
            "-99999999999999999999999999999"
        };
        for (const std::string& line : malformed) {
            expect<std::runtime_error>([&]{readScore(line);}, "Bad input");
        }
        for (const std::string& line : {std::string("-1"), std::string("101"),
                                       std::to_string(INT_MIN), std::to_string(INT_MAX)}) {
            expect<std::out_of_range>([&]{readScore(line);}, "Bad score");
        }
        const std::vector<std::string> inputs = {
            "", "\n", "\n\n", "0\n100\n", "42",
            "bad\n-1\n101 extra\n\n100\n0",
            " 5 \r\nno\r\n 6\r\n",
            "1\n999999999999999999999999\n2"
        };
        const std::vector<std::vector<int>> wanted = {
            {}, {}, {}, {0,100}, {42}, {100,0}, {5,6}, {1,2}
        };
        const std::vector<std::string> messages = {
            "", "Bad input\n", "Bad input\nBad input\n", "", "",
            "Bad input\nBad score\nBad input\nBad input\n",
            "Bad input\n", "Bad input\n"
        };
        for (std::size_t i=0; i<inputs.size(); ++i) {
            std::istringstream input(inputs.at(i));
            std::ostringstream output;
            check(collectScores(input,output)==wanted.at(i), "collection case " + std::to_string(i));
            check(output.str()==messages.at(i), "exact errors case " + std::to_string(i));
        }
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
