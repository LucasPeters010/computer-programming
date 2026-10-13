#include "exercise.hpp"

// Public smoke checks, not an exhaustive grading suite. Add your own cases.
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
        StudyRoom r("West");
        check(r.reserve(13,15) && r.reserve(9,11), "valid bookings");
        check(!r.reserve(10,12) && r.reserve(11,13), "overlap and adjacency");
        check(r.bookedHours()==6, "duration");
        check(r.cancel(11,13) && !r.cancel(11,13), "exact cancellation");
        check(r.isFree(11,13) && !r.isFree(23,25), "availability");
        check(r.schedule()=="West: [9,11) [13,15)", "sorted schedule");
        std::cout << "Public checks passed. Add the edge cases from README.md.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unexpected uncaught custom exception.\n";
        return 1;
    }
}
