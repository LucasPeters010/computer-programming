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

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    int rows() const;
    int cols() const;
    int& at(int row, int col);
    const int& at(int row, int col) const;
    void resize(int newRows, int newCols);

private:
    // Choose fields and helper declarations.
};
