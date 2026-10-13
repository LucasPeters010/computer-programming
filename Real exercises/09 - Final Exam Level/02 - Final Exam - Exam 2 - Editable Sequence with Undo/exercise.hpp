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

class SequenceEditor {
public:
    SequenceEditor();
    ~SequenceEditor();
    int size() const;
    int at(int index) const;
    void insert(int index, int value);
    int erase(int index);
    void resize(int n);
    bool hasUndo() const;
    void undo();
    std::string toString() const;
    void applyBatch(std::istream& input);
    SequenceEditor(const SequenceEditor&) = delete;
    SequenceEditor& operator=(const SequenceEditor&) = delete;

private:
    // Choose fields and helper declarations.
};
