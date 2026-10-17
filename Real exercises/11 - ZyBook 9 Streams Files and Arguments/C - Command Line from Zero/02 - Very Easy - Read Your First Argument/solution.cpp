#include "exercise.hpp"

int run(int argc, const char* const argv[], std::ostream& output) {
    // SUPPLIED: do not access argv[1] until you know it exists.
    if(argc!=2) { output<<"Usage: app.exe name\n"; return 1; }
    (void)argv;
    // TODO: replace the throw with one output statement using argv[1].
    throw std::logic_error("Not implemented");
    return 0; // SUPPLIED: zero means successful execution.
}
