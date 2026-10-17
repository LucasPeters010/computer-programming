#pragma once
#include <stdexcept>

class TinyCounter {
public:
    explicit TinyCounter(int n) : number(n) {}
    // Supplied: ordinary integer fields can be copied independently.
    TinyCounter(const TinyCounter& other) : number(other.number) {}
    int get() const { return number; }
    void set(int n) { number = n; }
private:
    int number;
};
int changeLocal(TinyCounter local, int replacement);
