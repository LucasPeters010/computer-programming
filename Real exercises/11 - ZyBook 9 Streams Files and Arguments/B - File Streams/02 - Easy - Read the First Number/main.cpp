#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        test::TempFiles f;
        check(firstNumber(f.write("numbers.txt","  -7 8"))==-7,"first only");
        check(firstNumber(f.write("zero.txt","0"))==0,"zero");
        expect<std::runtime_error>([&]{firstNumber(f.path("absent"));},"Cannot open");
        for(const std::string& text:{"", "  ", "hello", "99999999999999999999999"}) {
            std::string path=f.write("bad.txt",text);
            expect<std::runtime_error>([&]{firstNumber(path);},"No number");
        }
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
