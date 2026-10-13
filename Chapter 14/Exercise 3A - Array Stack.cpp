// Exercise 3A - Array Stack (MEDIUM, before linked nodes)
// Goal: Understand a normal stack using a dynamic array inside a class.
// A stack is LIFO: LAST IN, FIRST OUT.
// No Node or next pointers in this exercise!
//
// Tasks:
// 1. push(value): store value at the top, then increase count.
// 2. top(): return the newest value without removing it.
// 3. pop(): remove the newest value by decreasing count.
// Constructor and destructor are provided so you can focus on the stack.
//
// Expected output after the TODOs:
// Top: 30
// After pop: 20
//
// Hints:
// - count is how many elements are in the stack.
// - The next free slot is data[count].
// - The current top is at index count - 1.
// - Don't use delete in pop(): the array gets deleted by ~ArrayStack().

#include <iostream>
#include <stdexcept>

class ArrayStack {
public:
    ArrayStack(int maxSize)
        : data(new int[maxSize]), capacity(maxSize), count(0) {}

    ~ArrayStack() {
        delete[] data;
    }

    void push(int value) {
        if (count == capacity) {
            throw std::runtime_error("Stack is full");
        }
        // TODO 1: Put value into the next free slot and increase count.

        data[count + 1] = value;
        count += 1;

    }

    int top() const {
        if (count == 0) {
            throw std::runtime_error("Stack is empty");
        }
        // TODO 2: Return the newest value, using count.
        return data[count];
    }

    void pop() {
        if (count == 0) {
            throw std::runtime_error("Stack is empty");
        }
        count -= 1;
        // TODO 3: Decrease count. Do NOT use delete here.
    }

private:
    int* data;     // Points to a dynamically allocated array.
    int capacity;  // Maximum number of values.
    int count;     // Number of values currently stored.
};

int main() {
    ArrayStack numbers(5);
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Top: " << numbers.top() << '\n';
    numbers.pop();
    std::cout << "After pop: " << numbers.top() << '\n';
}
