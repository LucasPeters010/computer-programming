#include "exercise.hpp"
#include "../test_support.hpp"
int main() {
    try {
        BST tree;
        for (int mode = 0; mode < 3; ++mode) {
            bool threw = false;
            try { if (mode == 0) tree.rootKey(); else if (mode == 1) tree.leftKey(); else tree.rightKey(); }
            catch (const std::out_of_range&) { threw = true; }
            check(threw, "missing node must throw out_of_range");
        }
        tree.insert(12, "root");
        check(tree.rootKey() == 12, "read root key");
        bool leftMissing = false, rightMissing = false;
        try { tree.leftKey(); } catch (const std::out_of_range&) { leftMissing = true; }
        try { tree.rightKey(); } catch (const std::out_of_range&) { rightMissing = true; }
        check(leftMissing && rightMissing, "root alone has no children");
        tree.insert(5, "left"); tree.insert(19, "right");
        tree.insert(2, "grandchild"); tree.insert(24, "grandchild");
        const BST& view = tree;
        check(view.rootKey() == 12 && view.leftKey() == 5 && view.rightKey() == 19, "direct children, not extreme descendants");
        check(tree.preOrder() == std::vector<int>({12,5,2,19,24}), "reading preserves tree");
        std::cout << "All checks passed.\n";
    } catch (const std::exception& e) { std::cerr << "Not finished: " << e.what() << '\n'; return 1; }
}
