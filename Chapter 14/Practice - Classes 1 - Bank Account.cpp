// Classes 1 - Bank Account (EASY)
// Practice: constructors, private fields, member functions.
// TODO: implement deposit(), withdraw(), and getBalance().
// Rule: a withdrawal must not make the balance negative.
// Expected output after deposit(25) and withdraw(10): Balance: 115

#include <iostream>

class BankAccount {
public:
    BankAccount(int startBalance) : balance(startBalance) {}

    void deposit(int amount) {
        // TODO: add amount only if amount > 0
        if(amount > 0){
            balance += amount;
        }
    }

    void withdraw(int amount) {
        // TODO: subtract amount only if amount > 0 and amount <= balance
        if(amount > 0 && amount <= balance){
            balance -= amount;
        }
    }

    int getBalance() const {
        // TODO: return the balance
        return balance;
    }

private:
    int balance;
};

int main() {
    BankAccount account(100);
    account.deposit(25);
    account.withdraw(10);
    std::cout << "Balance: " << account.getBalance() << '\n';
}
