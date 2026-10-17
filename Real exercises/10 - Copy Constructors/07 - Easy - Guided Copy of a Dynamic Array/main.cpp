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
        for (int n : {0, 1, 3, 40}) {
            NumberArray a(n);
            for (int i = 0; i < n; ++i) a.at(i) = i % 3 - 1;
            NumberArray b(a);
            check(b.size() == n, "copy length, including zero");
            for (int i = 0; i < n; ++i) {
                check(&a.at(i) != &b.at(i), "allocate separate array");
                check(b.at(i) == a.at(i), "copy every element");
            }
            if (n > 0) {
                b.at(0) = 88; a.at(n-1) = 99;
                check(a.at(0) == (n == 1 ? 99 : -1), "copy mutation is independent");
                check(b.at(n-1) == (n == 1 ? 88 : (n-1)%3-1), "source mutation is independent");
            }
            const NumberArray c(b);
            NumberArray d(c);
            check(d.size() == n, "copy of const copy");
            if (n > 0) check(&d.at(0) != &c.at(0) && d.at(0) == c.at(0), "copy of copy data");
        }
        NumberArray* source = new NumberArray(2);
        source->at(0) = 11; source->at(1) = -4;
        NumberArray survivor(*source);
        check(&source->at(0) != &survivor.at(0), "independent storage before delete");
        delete source;
        check(survivor.at(0) == 11 && survivor.at(1) == -4, "survives source destruction");
        NumberArray empty(0); NumberArray emptyCopy(empty);
        bool threw = false;
        try { emptyCopy.at(0); } catch (const std::out_of_range&) { threw = true; }
        check(threw, "empty copy has no element zero");
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
