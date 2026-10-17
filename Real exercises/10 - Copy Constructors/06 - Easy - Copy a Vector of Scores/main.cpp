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
        for (const std::vector<int>& values : {std::vector<int>{}, std::vector<int>{7}, std::vector<int>{8, -4, 8, 0}}) {
            const ScoreList a(values);
            ScoreList b(a);
            check(b.size() == a.size(), "copy size including empty vector");
            for (int i = 0; i < a.size(); ++i) {
                check(b.at(i) == a.at(i), "preserve every value and its order");
                check(&a.at(i) != &b.at(i), "independent vector elements");
            }
            b.add(99);
            check(a.size() == static_cast<int>(values.size()), "adding to copy does not change source");
            ScoreList c(b);
            b.at(0) = -50;
            check(c.at(0) != -50, "copy of copy is independent");
        }
        std::cout << "All example and edge-case checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
