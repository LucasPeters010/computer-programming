// Streams 2 - Format Receipt (MEDIUM)
// Practice: ostringstream, fixed, setprecision.
// TODO: Build a receipt string using std::ostringstream.
// The receipt should contain title, quantity, and total to two decimals.
// Expected output: Apples x3 = EUR 4.50

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

std::string receipt(std::string name, int quantity, double unitPrice) {
    std::ostringstream output;

    // TODO: Write formatted text to output.
    // Hint: output << std::fixed << std::setprecision(2);

    return output.str();
}

int main() {
    std::cout << receipt("Apples", 3, 1.5) << '\n';
}
