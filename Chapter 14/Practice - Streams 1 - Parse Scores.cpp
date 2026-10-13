// Streams 1 - Parse Scores (EASY-MEDIUM)
// Practice: istringstream and extracting values.
// TODO: Read ALL integers from the line into total and count.
// Hint: while (input >> number)
// Expected output: Count: 4, Sum: 30

#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line = "5 10 7 8";
    std::istringstream input(line);
    int number;
    int total = 0;
    int count = 0;

    // TODO: Read values using input >> number in a while loop.
    while(input >> number){
        count += 1;
        total += number;
    }

    std::cout << "Count: " << count << ", Sum: " << total << '\n';
}
