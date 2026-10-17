#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        test::TempFiles f;
        writeNote(f.path("note.txt"),"Hello Lucas");check(f.read("note.txt")=="Hello Lucas\n","new file");
        writeNote(f.path("note.txt"),"Hi");check(f.read("note.txt")=="Hi\n","replace old content");
        writeNote(f.path("empty.txt"),"");check(f.read("empty.txt")=="\n","empty text");
        expect<std::runtime_error>([&]{writeNote(f.path("missing-parent/note.txt"),"x");},"Cannot write");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
