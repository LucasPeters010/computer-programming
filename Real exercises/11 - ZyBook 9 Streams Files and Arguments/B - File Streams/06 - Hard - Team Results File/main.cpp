#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        test::TempFiles f;std::ostringstream out;
        teamReport(f.write("teams.txt","Red Team\n5 2\nBlue Team\n3\nGreen\nbad\nLast\n0 0"),out);
        check(out.str()=="Red Team: 5 wins, 2 losses\nBlue Team: 3 wins, 0 losses\nGreen: Invalid\nLast: 0 wins, 0 losses\n","example and recovery");
        std::ostringstream empty;teamReport(f.write("empty.txt",""),empty);check(empty.str().empty(),"empty");
        const std::vector<std::string> bad={"", "-1", "1001 0", "1 2 3", "1x", "2 -1", "2 1001", "2.5", "999999999999999999999999", "1 999999999999999999999999"};
        for(const std::string& line:bad){std::ostringstream result;teamReport(f.write("bad.txt","A\n"+line+"\nB\n7\n"),result);check(result.str()=="A: Invalid\nB: 7 wins, 0 losses\n","bad record recovery: "+line);}
        std::ostringstream tail;teamReport(f.write("tail.txt","A\n1 2\nB"),tail);check(tail.str()=="A: 1 wins, 2 losses\nB: Invalid\n","missing final statistics");
        std::ostringstream boundary;teamReport(f.write("boundary.txt","X\n 1000 1000 \n"),boundary);check(boundary.str()=="X: 1000 wins, 1000 losses\n","boundary values");
        expect<std::runtime_error>([&]{teamReport(f.path("missing"),out);},"Cannot open");
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
