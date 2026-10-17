#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class ScoreList {
public:
    explicit ScoreList(const std::vector<int>& values) : scores(values) {}
    int size() const { return static_cast<int>(scores.size()); }
    int& at(int index) { return scores.at(index); }
    const int& at(int index) const { return scores.at(index); }
    void add(int value) { scores.push_back(value); }
    ScoreList(const ScoreList& other);
    ScoreList& operator=(const ScoreList&) = delete;
private:
    std::vector<int> scores;
};
