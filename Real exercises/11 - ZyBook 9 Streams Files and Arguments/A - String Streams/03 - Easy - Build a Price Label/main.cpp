#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        check(priceLabel("Book",4.5)=="Book: 4.50","example");
        check(priceLabel("",0)==": 0.00","empty name and zero");
        check(priceLabel("Blue pen",12.375)=="Blue pen: 12.38","rounding and spaces");
        check(priceLabel("A",1)=="A: 1.00","repeat call starts empty");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
