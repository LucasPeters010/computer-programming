#include "exercise.hpp"
#include <cstdlib>
#include <iostream>
#include <climits>

// Exit immediately on failure: a shallow copy must not reach two destructors.
void check(bool ok, const char* message) {
    if (!ok) { std::cerr << "FAIL: " << message << std::endl; std::exit(1); }
}
int main() {
    try {
        Triple a(8, -4, 0);
        Triple b(a);
        check(&a.at(0) != &b.at(0), "copy owns a new array");
        check(b.at(0) == 8 && b.at(1) == -4 && b.at(2) == 0, "all three values in order");
        b.at(0) = 99; a.at(2) = 77;
        check(a.at(0) == 8 && b.at(2) == 0, "changes independent both ways");
        const Triple c(b);
        Triple d(c);
        check(&d.at(0) != &c.at(0) && d.at(1) == -4, "copy from const copy");
        Triple* source = new Triple(INT_MIN, INT_MAX, INT_MIN);
        Triple survivor(*source);
        check(&source->at(0) != &survivor.at(0), "source and survivor have separate storage");
        delete source;
        check(survivor.at(0) == INT_MIN && survivor.at(1) == INT_MAX && survivor.at(2) == INT_MIN, "values survive source destruction");
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
