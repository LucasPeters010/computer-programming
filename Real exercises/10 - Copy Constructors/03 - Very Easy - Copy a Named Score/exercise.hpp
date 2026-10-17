#pragma once
#include <string>
#include <vector>
#include <stdexcept>

// All infrastructure is supplied. Implement only the copy constructor.
class NamedScore {
public:
    NamedScore(const std::string& text, int n) : name(text), score(n) {}
    std::string getName() const { return name; }
    int getScore() const { return score; }
    void set(const std::string& text, int n) { name = text; score = n; }
    NamedScore(const NamedScore& other);
    NamedScore& operator=(const NamedScore&) = delete;
private:
    std::string name;
    int score;
};
