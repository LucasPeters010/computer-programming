#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        test::TempFiles f;
        check(countWords(f.write("words.txt","red blue\nred"))==3,"example");
        check(countWords(f.write("empty.txt"," \n\t"))==0,"whitespace only");
        check(countWords(f.write("one.txt","last"))==1,"no final newline");
        check(countWords(f.write("one.txt","last\n"))==1,"final newline");
        check(countWords(f.write("punct.txt","a, a 42"))==3,"tokens count");
        expect<std::runtime_error>([&]{countWords(f.path("missing"));},"Cannot open");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
