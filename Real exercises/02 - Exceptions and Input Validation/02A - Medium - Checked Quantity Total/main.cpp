#include "exercise.hpp"

namespace {
void check(bool condition, const std::string& label) {
    if (!condition) throw std::runtime_error("Check failed: " + label);
}
}
int main() {
    try {
        check(checkedTotal({4,0,12})==16, "example total");
        check(checkedTotal({0})==0, "zero is valid");
        check(checkedTotal({1000})==1000, "upper boundary is valid");
        check(checkedTotal({0,1000,0,1000})==2000, "boundaries and duplicates");
        check(checkedTotal(std::vector<int>(100,1000))==100000, "many valid entries");
        bool emptyCaught=false;
        try { checkedTotal({}); }
        catch (const std::runtime_error& e) {
            emptyCaught=true;
            check(std::string(e.what())=="No quantities", "empty message");
        }
        check(emptyCaught, "empty input must throw");
        const std::vector<std::vector<int>> bad = {
            {-1}, {1001}, {INT_MIN}, {INT_MAX},
            {0,-7,5}, {0,1000,1001}, {-2,1001}, {5,1001,-2}
        };
        const std::vector<int> positions={0,0,0,0,1,2,0,1};
        for (std::size_t i=0;i<bad.size();++i) {
            std::vector<int> values=bad.at(i);
            bool caught=false;
            try { checkedTotal(values); }
            catch (const InvalidQuantity& e) {
                caught=true;
                check(e.position()==positions.at(i), "first invalid index");
                check(e.value()==bad.at(i).at(positions.at(i)), "invalid value payload");
            }
            check(caught, "InvalidQuantity required");
            check(values==bad.at(i), "invalid input unchanged");
        }
        std::vector<int> values={7,0,3};
        check(checkedTotal(values)==10 && values==std::vector<int>({7,0,3}), "valid input unchanged");
        const InvalidQuantity error(8,-15);
        check(error.position()==8 && error.value()==-15, "exception getters");
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
