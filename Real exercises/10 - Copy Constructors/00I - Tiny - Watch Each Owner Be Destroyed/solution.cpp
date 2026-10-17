#include "exercise.hpp"

// Each object owns exactly ONE int. The copy constructor is already correct.
// Your job: release THIS object's allocation, not the other object's allocation.
OwnedNumber::~OwnedNumber() noexcept(false) {
    // One statement: release the single integer that data points to.
    // It was allocated with new int, NOT new int[...].
    // TODO START
    throw std::logic_error("Not implemented");
    // TODO END
    --liveIntegers; // Supplied bookkeeping, not part of your task.
    std::cout << "Destructor finished; integers still alive: " << liveIntegers << '\n';
}
