#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        test::TempFiles f;
        check(canOpen(f.write("empty.txt","")),"empty existing file");
        check(canOpen(f.write("with spaces.txt","hello")),"filename with spaces");
        check(!canOpen(f.path("missing.txt")),"missing file");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
