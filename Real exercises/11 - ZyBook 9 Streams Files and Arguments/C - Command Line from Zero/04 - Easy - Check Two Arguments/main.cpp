#include "exercise.hpp"

#ifdef EXERCISE_APP
// Real application mode: the operating system supplies argc and argv.
int main(int argc, char* argv[]) {
    try { return run(argc,argv,std::cout); }
    catch(const std::exception& e) { std::cerr<<"Not finished: "<<e.what()<<'\n'; return 1; }
}
#else
#include "../../test_support.hpp"
using test::check;
using test::expect;
// Supplied tests simulate argv; do NOT implement this helper.
void checkRun(const std::vector<std::string>& words,int code,const std::string& expected) {
    std::vector<const char*> pointers;
    for (const std::string& word:words) pointers.push_back(word.c_str());
    pointers.push_back(nullptr); // Like the operating system's argv[argc].
    std::ostringstream output;
    const int actual=run(static_cast<int>(words.size()),pointers.data(),output);
    check(actual==code,"exit code for supplied arguments");
    check(output.str()==expected,"exact output: expected ["+expected+"], got ["+output.str()+"]");
}
int main() {
    try {
        checkRun({"app.exe","Lucas","Amsterdam"},0,"Lucas lives in Amsterdam.\n");
        checkRun({"app.exe","Mary Jo","New York"},0,"Mary Jo lives in New York.\n");
        checkRun({"app.exe"},1,"Usage: app.exe name city\n");
        checkRun({"app.exe","Lucas"},1,"Usage: app.exe name city\n");
        checkRun({"app.exe","a","b","c"},1,"Usage: app.exe name city\n");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
#endif
