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

class TextStack {
public:
    TextStack();
    ~TextStack();
    void push(int value);
    int pop();
    bool empty() const;
    TextStack(const TextStack&) = delete;
    TextStack& operator=(const TextStack&) = delete;

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

void loadNumbers(std::istream& input, TextStack& stack);
