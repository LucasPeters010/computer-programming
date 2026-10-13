// Classes 2 - Library Book (EASY-MEDIUM)
// Practice: classes, const methods, and object state.
// TODO: borrow() changes available to false, returnBook() to true.
// printStatus() should print the title and Available/Borrowed.
// Expected output:
// C++ Basics: Available
// C++ Basics: Borrowed
// C++ Basics: Available

#include <iostream>
#include <string>

class Book {
public:
    Book(std::string newTitle) : title(newTitle), available(true) {}

    void borrow() {
        // TODO: if available, mark as borrowed
        if(available == true){
            available = false;
        }
    }

    void returnBook() {
        available = true;
        // TODO: mark as available
    }

    void printStatus() const {
        // TODO: print the title and status
        if(available == true){
            std::cout << title << ": Available" << std::endl;
        }
        else{
            std::cout << title << ": Borrowed " << std::endl;
        }
    }

private:
    std::string title;
    bool available;
};

int main() {
    Book book("C++ Basics");
    book.printStatus();
    book.borrow();
    book.printStatus();
    book.returnBook();
    book.printStatus();
}
