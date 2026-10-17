#include "exercise.hpp"

NamedScore::NamedScore(const NamedScore& other) : name(), score(0) {
    // TODO: Copy the name and score. A std::string already manages its own copying; do not allocate memory yourself.
    (void)other;
    throw std::logic_error("Not implemented");
}
