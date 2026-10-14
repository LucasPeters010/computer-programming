#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// Preserve the public signatures; use the supplied private fields and add helpers if needed.

class IntList {
public:
    IntList();
    ~IntList();
    void append(int value);
    int removeAll(int value);
    std::vector<int> toVector() const;
    IntList(const IntList&) = delete;
    IntList& operator=(const IntList&) = delete;

private:
    class Node {
    public:
        Node(int value) : value(value), next(nullptr) {}
        int value;
        Node* next;
    };
    Node* head;
    // Add helper declarations if needed.
};
