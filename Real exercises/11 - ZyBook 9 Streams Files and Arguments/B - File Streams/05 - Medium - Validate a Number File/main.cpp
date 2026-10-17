#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {

        test::TempFiles f;
        check(checkedFileTotal(f.write("numbers.txt","8 -4 6\n"))==10,"example");
        check(checkedFileTotal(f.write("empty.txt"," \n\t"))==0,"empty");
        check(checkedFileTotal(f.write("limits.txt","2147483647 2147483647"))==4294967294LL,"wide sum");
        for(const std::string& text:{"bad", "3.5", "2x", "1 999999999999999999999999", "1 2 bad 3"}) {
            std::string path=f.write("bad.txt",text);
            expect<std::runtime_error>([&]{checkedFileTotal(path);},"Invalid number");
        }
        expect<std::runtime_error>([&]{checkedFileTotal(f.path("missing"));},"Cannot open");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
