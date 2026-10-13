// Exercise 4 - Build a Queue (HARD)
// Goal: Build a linked queue from scratch using classes and pointers.
//
// A queue is FIFO: first in, first out.
// Example: enqueue(10), enqueue(20), enqueue(30), dequeue()
// leaves 20 at the front.
//
// Tasks (recommended order):
// 1. Complete enqueue(): append a Node to the BACK of the queue.
// 2. Complete front(): read the value at the FRONT.
// 3. Complete dequeue(): remove the FRONT node safely.
// 4. Complete ~Queue(): delete all remaining nodes.
//
// Expected output after completing all TODOs:
// Front: 10
// Front after dequeue: 20
//
// Pointer rules:
// - When empty, both first and last should be nullptr.
// - When adding the first node, both first and last point to it.
// - When deleting the final node, reset last to nullptr.
// - Each deleted node should be freed exactly once.

#include <iostream>
#include <stdexcept>

class Queue {
public:
    Queue() : first(nullptr), last(nullptr) {}

    ~Queue() {
        // TODO 4: Keep removing nodes until the queue is empty.
        while (!empty())
        {
            dequeue();
        }


        
    }

    void enqueue(int value) {

        Node* n = new Node(value);

        if (first == nullptr && last == nullptr)
        {
            first = n;
            last = n;
        }
        else{
            last->next = n;
            last = n;

        }
        
        
        // TODO 1: Allocate a node.
        // If empty: both first and last become that node.
        // Otherwise: connect last->next to the new node, then move last.
    }

    int front() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        // TODO 2: Return the value of the first node.
        return first->value;
    }

    void dequeue() {
        if (empty()) {
            throw std::runtime_error(" Queue is empty");
        }

        Node* temp = first;
        first = first->next;
        delete temp;

        if(first == nullptr){
            delete last;
        }
 
        // TODO 3: Save first, advance first, and delete old first.
        // If first becomes nullptr, set last to nullptr too.
    }

    bool empty() const {
        return first == nullptr;
    }

private:
    class Node {
    public:
        Node(int newValue) : value(newValue), next(nullptr) {}
        int value;
        Node* next;
    };

    Node* first;
    Node* last;
};

int main() {
    Queue numbers;
    numbers.enqueue(10);
    numbers.enqueue(20);
    numbers.enqueue(30);

    std::cout << "Front: " << numbers.front() << '\n';
    numbers.dequeue();
    std::cout << "Front after dequeue: " << numbers.front() << '\n';

    return 0;
}
