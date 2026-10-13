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

class StockItem {
public:
    StockItem(std::string sku, int quantity);
    std::string getSku() const;
    int available() const;
    int reserved() const;
    bool reserve(int q);
    bool release(int q);
    bool dispatch(int q);

private:
    // Choose fields and helper declarations.
};

class Warehouse {
public:
    Warehouse();
    bool addItem(std::string sku, int quantity);
    bool reserve(std::string sku, int q);
    bool release(std::string sku, int q);
    bool dispatch(std::string sku, int q);
    std::string report() const;

private:
    // Choose fields and helper declarations.
};
