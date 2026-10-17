#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        int value=91;
        check(parseInteger("  -12 \t",value)&&value==-12,"valid whitespace");
        check(parseInteger("+7",value)&&value==7,"plus sign");
        check(parseInteger(std::to_string(INT_MIN),value)&&value==INT_MIN,"minimum");
        check(parseInteger(std::to_string(INT_MAX),value)&&value==INT_MAX,"maximum");
        for(const std::string& s: {"", " ", "abc", "3.5", "3abc", "1 2", "99999999999999999999999"}) {
            value=91; check(!parseInteger(s,value)&&value==91,"reject and preserve: "+s);
        }
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
