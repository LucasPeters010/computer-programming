#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

// Preserve the public signatures; use the supplied private fields and add helpers if needed.

class Product {
public:
    Product(int id, int stock);
    int getId() const;
    int getStock() const;
    bool sell(int quantity);

private:
    int id;
    int stock;
    // Add helper declarations if needed.
};

class Shop {
public:
    Shop();
    bool add(int id, int stock);
    bool sell(int id, int quantity);
    int totalStock() const;

private:
    std::vector<Product> products;
    // Add helper declarations if needed.
};
