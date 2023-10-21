#pragma once
#include <iostream>

class FactorialCalculator
{
private:
    unsigned long long n;
    unsigned long long result;

public:
    FactorialCalculator(unsigned long long _n) : n(_n), result(1) {}

    void Calculate();
    inline unsigned long long GetN() { return n; }
    inline unsigned long long GetResult() { return result; }
};

