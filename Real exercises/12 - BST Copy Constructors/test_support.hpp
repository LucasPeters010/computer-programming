#pragma once
#include <cstdlib>
#include <iostream>
#include <set>

// Stop before destructors on a failed check: sharing nodes could double-delete.
inline void check(bool condition, const char* message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << std::endl;
        std::exit(1);
    }
}
struct TestAccess {
    static void gather(const BST::Node* node, std::set<const BST::Node*>& seen) {
        if (node == nullptr) return;
        check(seen.insert(node).second, "cycle or node reused within one tree");
        gather(node->left, seen);
        gather(node->right, seen);
    }
    static bool sameShape(const BST::Node* a, const BST::Node* b) {
        if (a == nullptr || b == nullptr) return a == b;
        return a->key == b->key && a->value == b->value
            && sameShape(a->left, b->left) && sameShape(a->right, b->right);
    }
    static void independent(const BST& source, const BST& copy) {
        std::set<const BST::Node*> oldNodes, newNodes;
        gather(source.root, oldNodes);
        gather(copy.root, newNodes);
        for (const BST::Node* n : newNodes)
            check(oldNodes.count(n) == 0, "copy shares a node address with source");
        check(sameShape(source.root, copy.root), "preserve every key, value and missing child");
    }
};
inline void fill(BST& tree, const std::vector<int>& keys) {
    for (int key : keys) tree.insert(key, "value " + std::to_string(key));
}
inline bool missing(const BST& tree, int key) {
    try { (void)tree.getValue(key); }
    catch (const std::out_of_range&) { return true; }
    return false;
}
