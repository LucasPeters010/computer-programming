// Exceptions 1 - Safe Divide (EASY)
// Practice: throw and catch.
// TODO: Throw std::invalid_argument if denominator is 0.
// Then catch the exception in main() and print its what() message.
// Expected output for 12 / 0: Error: Cannot divide by zero

#include <iostream>
#include <stdexcept>

double safeDivide(double numerator, double denominator) {
    // TODO: If denominator == 0, throw std::invalid_argument
    return numerator / denominator;
}

int main() {
    // TODO: Put the call in a try block and catch std::exception.
    // Print "Error: " followed by e.what().
    std::cout << safeDivide(12, 0) << '\n';
}
