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

class LinkedStack {
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int top() const;
    int pop();
    LinkedStack(const LinkedStack&) = delete;
    LinkedStack& operator=(const LinkedStack&) = delete;

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
