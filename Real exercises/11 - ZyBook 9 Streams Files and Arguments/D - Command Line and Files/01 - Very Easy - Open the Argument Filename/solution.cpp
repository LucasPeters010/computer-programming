#include "exercise.hpp"

int run(int argc, const char* const argv[], std::ostream& output) {
    // Step 1 SUPPLIED: there must be exactly one filename argument.
    if(argc!=2) { output<<"Usage: app.exe filename\n"; return 1; }
    std::ifstream input;
    (void)argv;
    // Step 2 YOUR TASK: open argv[1] using input (one statement).
    throw std::logic_error("Not implemented");
    // Step 3 SUPPLIED: do not proceed if opening failed.
    if(!input.is_open()) { output<<"Cannot open\n"; return 1; }
    output<<"Opened\n";
    return 0;
}
