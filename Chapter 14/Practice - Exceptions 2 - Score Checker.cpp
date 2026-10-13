// Exceptions 2 - Score Checker (MEDIUM)
// Practice: class validation, throw, try/catch.
// TODO: setScore() rejects numbers outside 0..100 with out_of_range.
// TODO: use try/catch in main so the program continues after bad input.
// Expected behavior: score 85 succeeds; score 120 is caught.

#include <iostream>
#include <stdexcept>

class Exam {
public:
    Exam() : score(0) {}

    void setScore(int newScore) {
        // TODO: throw std::out_of_range for invalid scores
        score = newScore;
    }

    int getScore() const { return score; }

private:
    int score;
};

int main() {
    Exam exam;
    // TODO: try setting 85, then 120.
    // Catch std::out_of_range and print e.what().
    exam.setScore(85);
    std::cout << "Score: " << exam.getScore() << '\n';
}
