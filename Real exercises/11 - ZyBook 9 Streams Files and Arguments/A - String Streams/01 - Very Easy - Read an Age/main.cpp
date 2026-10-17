#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        check(readAge("Lucas 18")==18,"example");
        check(readAge("Amy 0")==0,"zero");
        check(readAge("  Jo\t99  ")==99,"whitespace");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
