#include "exercise.hpp"

// Original examples plus automatic boundary/error checks. Implement solution.cpp.
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
        std::istringstream in("BOOK 9 11\nBOOK 10 12\nHOURS\nBOOK 14 16 extra\nCLEAR\nHOURS\n");std::ostringstream out;runBookings(in,out);
        check(out.str()=="Booked\nUnavailable\n2\nInvalid command\n0\n","session");

        { BookingDesk a;check(a.hours()==0,"empty hours");
          for(auto interval:std::vector<std::vector<int>>{{-1,1},{0,25},{5,5},{8,7},{24,25}})
              check(!a.book(interval[0],interval[1]) && a.hours()==0,"invalid interval unchanged");
          check(a.book(0,24) && a.hours()==24,"full day");
          check(!a.book(0,24) && !a.book(3,4) && a.hours()==24,"duplicate and contained overlap"); }
        { BookingDesk a;check(a.book(2,4) && a.book(10,12),"separate bookings");
          check(!a.book(11,13) && !a.book(1,3) && !a.book(1,14),"later/partial/enclosing overlap");
          check(a.hours()==4,"overlaps preserve hours");
          check(a.book(4,10) && a.book(0,2) && a.book(12,24) && a.hours()==24,"touching endpoints"); }
        { std::istringstream input("HOURS\nBOOK 0 1\nBOOK 2 3 extra\nHOURS\nCLEAR extra\nHOURS\nBOOK 4\nBOOK x 5\nBOOK 1 2.5\n\nWHAT\nCLEAR\nHOURS\n BOOK 23 24 \nHOURS");
          std::ostringstream output;runBookings(input,output);
          check(output.str()=="0\nBooked\nInvalid command\n1\nInvalid command\n1\nInvalid command\nInvalid command\nInvalid command\nInvalid command\nInvalid command\n0\nBooked\n1\n","strict syntax, state preservation and recovery"); }
        { std::istringstream input("BOOK -1 2\nBOOK 2 2\nBOOK 0 25\nHOURS\n");std::ostringstream output;runBookings(input,output);
          check(output.str()=="Unavailable\nUnavailable\nUnavailable\n0\n","invalid hours output"); }
        { std::istringstream input;std::ostringstream output;runBookings(input,output);check(output.str().empty(),"empty session"); }

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
