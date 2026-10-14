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

class Queue {
public:
    Queue();
    ~Queue();
    void push(int value);
    int front() const;
    int pop();
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

private:
    class Node {
    public:
        Node(int value) : value(value), next(nullptr) {}
        int value;
        Node* next;
    };
    Node* first;
    Node* last;
    // Add helper declarations if needed.
};
