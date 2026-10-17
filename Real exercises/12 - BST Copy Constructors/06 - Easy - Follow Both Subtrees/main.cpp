#include "exercise.hpp"
#include "../test_support.hpp"
int main() {
    try {
        for (const std::vector<int>& keys : std::vector<std::vector<int>>{{}, {12}, {12, 5, 19, 2, 8, 16, 24}, {5, 4, 3, 2}, {1, 2, 3, 4}}) {
            BST tree; fill(tree, keys);
            const BST& view = tree;
            check(view.count() == static_cast<int>(keys.size()), "count every node exactly once");
            check(view.count() == static_cast<int>(keys.size()), "count has no side effects");
        }
        std::cout << "All checks passed.\n";
    } catch (const std::exception& e) { std::cerr << "Not finished: " << e.what() << '\n'; return 1; }
}
