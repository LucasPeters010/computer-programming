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
        for (const std::string& text : {std::string(""), std::string("Lucas Peters"), std::string(200, 'x')}) {
            const NamedScore a(text, -5);
            NamedScore b(a);
            check(b.getName() == text && b.getScore() == -5, "copy string and number");
            b.set("Changed", 100);
            check(a.getName() == text && a.getScore() == -5, "string changes are independent");
            NamedScore c = b;
            b.set("Again", 0);
            check(c.getName() == "Changed" && c.getScore() == 100, "copy of copy is independent");
        }
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
