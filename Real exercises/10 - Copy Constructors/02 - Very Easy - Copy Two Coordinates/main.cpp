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
        for (int value : {0, -4, INT_MAX}) {
            Point a(value, -9);
            Point b(a);
            check(b.getX() == value && b.getY() == -9, "copy BOTH coordinates");
            a.set(12, 13);
            check(b.getX() == value && b.getY() == -9, "source changes do not alter copy");
            b.set(-1, -2);
            check(a.getX() == 12 && a.getY() == 13, "copy changes do not alter source");
            const Point c(b);
            Point d(c);
            check(d.getX() == -1 && d.getY() == -2, "copy of a const copy");
        }
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
