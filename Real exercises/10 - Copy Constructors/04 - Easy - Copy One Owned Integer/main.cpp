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
        for (int value : {0, -12, INT_MAX}) {
            const IntBox a(value);
            IntBox b(a);
            check(&a.at() != &b.at(), "allocate a separate integer, not the same pointer");
            check(b.at() == value, "copy the stored number");
            b.at() = 9;
            check(a.at() == value, "changing copy must not change original");
            IntBox c(b);
            check(&c.at() != &b.at() && c.at() == 9, "independent copy of copy");
        }
        IntBox* source = new IntBox(31);
        IntBox survivor(*source);
        check(&source->at() != &survivor.at(), "separate storage before destruction");
        source->at() = -1;
        check(survivor.at() == 31, "source mutation leaves copy unchanged");
        delete source;
        check(survivor.at() == 31, "copy survives destruction of source");
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
