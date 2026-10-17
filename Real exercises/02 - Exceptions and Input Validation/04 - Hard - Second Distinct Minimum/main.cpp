#include "exercise.hpp"

// Examples and automatic edge-case checks; run with solution.cpp.
namespace {
void check(bool condition, const std::string& label) {
    if (!condition) throw std::runtime_error("Check failed: " + label);
}
[[maybe_unused]] bool close(double a, double b) {
    return std::abs(a-b) < 1e-9;
}
template<class Error, class Action>
void expect(Action action, const std::string& message) {
    try { action(); }
    catch (const Error& e) {
        check(std::string(e.what()) == message, "exception message: " + message);
        return;
    }
    throw std::runtime_error("Expected exception: " + message);
}
}

int main() {
    try {
        check(secondMinimum({4,1,1,3})==3,"distinct minimum");
        bool few=false;try{secondMinimum({9});}catch(const TooFewValues& e){few=e.count()==1;}check(few,"too few");
        bool same=false;try{secondMinimum({7,7});}catch(const AllEqual& e){same=e.value()==7;}check(same,"equal values");

        const std::vector<std::vector<int>> cases = {
            {1,2}, {2,1}, {1,1,2,2}, {8,4,6,1,5},
            {-5,-2,-9,-5}, {0,-1,0,1},
            {INT_MIN,INT_MAX}, {INT_MAX,INT_MIN,INT_MAX},
            {INT_MIN,INT_MIN,INT_MIN+1},
            {INT_MAX-1,INT_MAX,INT_MAX-1},
            {3,2,1}, {1,2,3}, {5,5,5,2,2,7}
        };
        const std::vector<int> answers = {
            2,2,2,4,-5,0,INT_MAX,INT_MAX,INT_MIN+1,INT_MAX,2,2,5
        };
        for (std::size_t i=0; i<cases.size(); ++i) {
            std::vector<int> values=cases.at(i);
            check(secondMinimum(values)==answers.at(i), "second distinct case " + std::to_string(i));
            check(values==cases.at(i), "input order unchanged");
        }
        for (const std::vector<int>& values : {std::vector<int>{}, std::vector<int>{INT_MIN}}) {
            bool caughtFew=false;
            try { secondMinimum(values); }
            catch (const TooFewValues& e) {
                caughtFew=true;
                check(e.count()==static_cast<int>(values.size()), "too-few count");
            }
            check(caughtFew, "TooFewValues takes priority for size zero or one");
        }
        for (int value : {0,-7,INT_MIN,INT_MAX}) {
            bool caughtEqual=false;
            std::vector<int> repeated(20,value);
            try { secondMinimum(repeated); }
            catch (const AllEqual& e) {
                caughtEqual=true;
                check(e.value()==value, "repeated value payload");
            }
            check(caughtEqual, "AllEqual required");
            check(repeated==std::vector<int>(20,value), "error leaves input unchanged");
        }
        check(TooFewValues(0).count()==0 && TooFewValues(1).count()==1, "count accessor");
        check(AllEqual(-9).value()==-9, "value accessor");
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
