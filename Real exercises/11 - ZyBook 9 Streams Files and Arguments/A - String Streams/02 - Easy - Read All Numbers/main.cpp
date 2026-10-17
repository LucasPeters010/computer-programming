#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        check(sumNumbers("8 4 6")==18,"example");
        check(sumNumbers("")==0 && sumNumbers(" \t ")==0,"empty");
        check(sumNumbers("-5 0 5")==0,"negative and zero");
        check(sumNumbers("7")==7 && sumNumbers("7 \n")==7,"last value once");
        check(sumNumbers("2147483647 2147483647")==4294967294LL,"wide sum");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
