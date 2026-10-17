#include "exercise.hpp"
#include "../../test_support.hpp"
using test::check;
using test::expect;
int main() {
    try {
        const std::vector<std::string> inputs={"", "80\nbad\n20", "\n", "0\n100\n", "3.5\n101\n5x\n999999999999999999999999\n 7 \n"};
        const std::vector<std::string> expected={"Count: 0\nTotal: 0\n", "Invalid line 2\nCount: 2\nTotal: 100\n", "Invalid line 1\nCount: 0\nTotal: 0\n", "Count: 2\nTotal: 100\n", "Invalid line 1\nInvalid line 2\nInvalid line 3\nInvalid line 4\nCount: 1\nTotal: 7\n"};
        for(std::size_t i=0;i<inputs.size();++i){std::istringstream input(inputs.at(i));std::ostringstream output;reportScores(input,output);check(output.str()==expected.at(i),"report case "+std::to_string(i));}
        std::cout << "All example and edge-case checks passed.\n";
        return 0;
    } catch(const std::exception& e) {
        std::cerr << "Not finished: " << e.what() << '\n';
        return 1;
    }
}
