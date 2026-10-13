// Exercise 3B - Linked Stack (MEDIUM+)
// Goal: Build the SAME stack as Exercise 3A, but with connected nodes.
//
// Compare with Exercise 3A:
// - Array stack: data[0], data[1], data[2]
// - Linked stack: head -> Node(30) -> Node(20) -> Node(10) -> nullptr
//
// Tasks:
// 1. push: allocate a new Node; connect it to old head; update head.
// 2. top: return the value inside head.
// 3. pop: save old head, move head, then delete old head.
// 4. Destructor: use pop() until the stack is empty.
//
// Expected output:
// Top: 30
// After pop: 20
//
// Hint: this Node destructor does NOT delete next automatically.
// Deleting one node therefore does not delete the entire chain.

#include <iostream>
#include <stdexcept>

class LinkedStack {
private:
    class Node {
    public:
        Node(int newValue) : value(newValue), next(nullptr) {}
        int value;
        Node* next;
    };

    Node* head;

public:
    LinkedStack() : head(nullptr) {}

    ~LinkedStack() {
        // TODO 4: While head is not nullptr, call pop().
    }

    void push(int value) {
        // TODO 1a: Allocate a Node using new.
        // TODO 1b: Set the new Node's next to head.
        // TODO 1c: Make head point to the new Node.
    }

    int top() const {
        if (head == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        // TODO 2: Return the value in head.
        return 0; // Replace this placeholder.
    }

    void pop() {
        if (head == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        // TODO 3a: Save the current head in a Node* variable.
        // TODO 3b: Move head to head->next.
        // TODO 3c: Delete the OLD head you saved.
    }
};

int main() {
    LinkedStack numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Top: " << numbers.top() << '\n';
    numbers.pop();
    std::cout << "After pop: " << numbers.top() << '\n';
}
