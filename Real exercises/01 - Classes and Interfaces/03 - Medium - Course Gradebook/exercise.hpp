#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Preserve the public signatures; choose your own private representation.

class StudentRecord {
public:
    StudentRecord(int id);
    int getId() const;
    bool addGrade(double mark, int weight);
    double average() const;
    bool complete() const;
    bool passed() const;

private:
    // Choose fields and helper declarations.
};

class Gradebook {
public:
    Gradebook();
    bool enroll(int id);
    bool record(int id, double mark, int weight);
    std::vector<int> passedIds() const;
    double cohortAverage() const;

private:
    // Choose fields and helper declarations.
};
