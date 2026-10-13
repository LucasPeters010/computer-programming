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

class StockTree {
public:
    StockTree();
    ~StockTree();
    void add(int id, int quantity);
    void sell(int id, int quantity);
    int stock(int id) const;
    long long totalStock() const;
    std::vector<int> lowStock(int limit) const;
    void write(std::ostream& output) const;
    StockTree(const StockTree&) = delete;
    StockTree& operator=(const StockTree&) = delete;

private:
    // Choose fields and helper declarations.
};

void runStockSession(std::istream& input, std::ostream& output);
