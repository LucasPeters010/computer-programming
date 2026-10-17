#pragma once
#include <stdexcept>

class TinyCounter {
public:
    explicit TinyCounter(int n) : number(n) {}
    TinyCounter(const TinyCounter& other);
    int get() const { return number; }
    void set(int n) { number = n; }
    TinyCounter& operator=(const TinyCounter&) = delete;
private:
    int number;
};
