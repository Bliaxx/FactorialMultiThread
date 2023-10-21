#pragma once
#include "FactorialCalculator.h"
#include "ThreadedPrinter.h"

class ThreadedTask
{
private:
    FactorialCalculator calculator;
    ThreadedPrinter& printer;

public:
    ThreadedTask(FactorialCalculator _calculator, ThreadedPrinter& _p) : calculator(_calculator), printer(_p) {}

    void operator()();
};

