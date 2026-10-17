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
        for (int cap : {0, 1, 5, 32}) {
            for (int used : {0, cap / 2, cap}) {
                CopyBuffer a(cap);
                for (int i = 0; i < used; ++i) a.push(i - 3);
                CopyBuffer b(a);
                check(b.size() == used && b.capacity() == cap, "copy size AND capacity separately");
                for (int i = 0; i < used; ++i) {
                    check(&a.at(i) != &b.at(i), "separate storage");
                    check(a.at(i) == b.at(i), "same used elements");
                }
                if (used > 0) {
                    b.at(0) = 90;
                    check(a.at(0) == -3, "copy mutation independent");
                    a.at(used - 1) = 91;
                    check(b.at(used - 1) == (used == 1 ? 90 : used - 4), "source mutation independent");
                }
                for (int i = used; i < cap; ++i) b.push(17);
                check(a.size() == used && b.size() == cap, "copy can use spare capacity independently");
                bool threw = false;
                try { b.push(1); } catch (const std::runtime_error&) { threw = true; }
                check(threw, "full copy rejects push");
                const CopyBuffer c(b); CopyBuffer d(c);
                check(d.size() == cap && d.capacity() == cap, "const copy of copy");
                if (cap > 0) check(&d.at(0) != &c.at(0) && d.at(0) == c.at(0), "copy of copy storage and values");
            }
        }
        CopyBuffer* source = new CopyBuffer(3); source->push(42);
        CopyBuffer survivor(*source);
        check(&source->at(0) != &survivor.at(0), "separate storage before source deletion");
        delete source;
        survivor.push(-7); survivor.push(0);
        check(survivor.at(0) == 42 && survivor.at(1) == -7 && survivor.size() == 3, "copy and spare capacity survive source deletion");
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
