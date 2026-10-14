#include "exercise.hpp"

// Add private fields/helpers in exercise.hpp and implementations here.

LinkedStack::LinkedStack() : head(nullptr) {}

LinkedStack::~LinkedStack() {
    while (head != nullptr) {
        Node* old = head;
        head = head->next;
        delete old;
    }
}

void LinkedStack::push(int value) {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

int LinkedStack::top() const {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

int LinkedStack::pop() {
    // Implement according to README.md.
    throw std::logic_error("Not implemented");
}

