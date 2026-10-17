#include "exercise.hpp"
#include "../test_support.hpp"

int main() {
    try {
        const std::vector<std::vector<int>> cases = {{}, {12}, {12, 5}, {12, 19}, {12, 5, 19, 2, 8, 16, 24, 9}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, {0, -9, 8, -12, -2, 3, 15}};
        for (const std::vector<int>& keys : cases) {
            {
                BST original; fill(original, keys);
                const BST& source = original;
                BST copy(source);
                TestAccess::independent(original, copy);
                BST third(copy);
                TestAccess::independent(copy, third);
                TestAccess::independent(original, third);
                if (!keys.empty()) {
                    const int key = keys.at(0);
                    copy.insert(key, "changed copy");
                    check(original.getValue(key) == "value " + std::to_string(key), "copy updates must not affect original");
                    original.insert(key, "changed original");
                    check(copy.getValue(key) == "changed copy", "original updates must not affect copy");
                    check(third.getValue(key) == "value " + std::to_string(key), "copy of copy remains independent");
                }
                copy.insert(1001, "new copy key");
                original.insert(-1001, "new original key");
                check(missing(original, 1001), "copy insertion independent");
                check(missing(copy, -1001), "original insertion independent");
            }
            {
                BST* original = new BST; fill(*original, keys);
                const std::vector<int> expected = original->preOrder();
                BST survivor(*original);
                TestAccess::independent(*original, survivor);
                delete original;
                check(survivor.preOrder() == expected, "copy survives source destruction, same pre-order");
                for (int key : keys) check(survivor.getValue(key) == "value " + std::to_string(key), "surviving string values");
                survivor.insert(1001, "still usable");
            }
            {
                BST original; fill(original, keys);
                const std::vector<int> expected = original.preOrder();
                { BST temporary(original); TestAccess::independent(original, temporary); }
                check(original.preOrder() == expected, "original survives copy destruction");
            }
        }
        std::cout << "All checks passed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
