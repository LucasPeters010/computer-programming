#include "exercise.hpp"

namespace {
void check(bool condition, const std::string& label) {
    if (!condition) throw std::runtime_error("Check failed: " + label);
}
}
int main() {
    try {
        check(withdraw(100,30)==70, "example withdrawal");
        check(withdraw(100,100)==0, "exact balance allowed");
        check(withdraw(1,1)==0, "smallest successful withdrawal");
        check(withdraw(INT_MAX,1)==INT_MAX-1, "large balance");
        check(withdraw(INT_MAX,INT_MAX)==0, "large exact balance");
        for (int amount : {0,-1,INT_MIN}) {
            for (int balance : {0,50,INT_MAX}) {
                bool caught=false;
                try { withdraw(balance,amount); }
                catch (const std::invalid_argument& e) {
                    caught=true;
                    check(std::string(e.what())=="Invalid amount", "invalid amount message");
                }
                check(caught, "nonpositive amount requires invalid_argument");
            }
        }
        const std::vector<int> balances={0,5,100,INT_MAX-1};
        const std::vector<int> amounts={1,6,INT_MAX,INT_MAX};
        for (std::size_t i=0;i<balances.size();++i) {
            bool caught=false;
            try { withdraw(balances.at(i),amounts.at(i)); }
            catch (const InsufficientFunds& e) {
                caught=true;
                check(e.requestedAmount()==amounts.at(i), "requested payload");
                check(e.availableAmount()==balances.at(i), "available payload");
            }
            check(caught, "InsufficientFunds required");
        }
        int balance=100;
        balance=withdraw(balance,30);
        try { balance=withdraw(balance,80); }
        catch (const InsufficientFunds&) {}
        check(balance==70, "failed call returns no replacement balance");
        balance=withdraw(balance,20);
        check(balance==50, "caller can continue after catching error");
        const InsufficientFunds error(12,7);
        check(error.requestedAmount()==12 && error.availableAmount()==7, "getters preserve arguments");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unexpected uncaught custom exception.\n";
        return 1;
    }
}
