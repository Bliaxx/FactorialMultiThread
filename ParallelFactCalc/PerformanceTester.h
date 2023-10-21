#pragma once
#include "ThreadedPrinter.h"
#include "ThreadedTask.h"
#include <vector>

class PerformanceTester {
private:
    ThreadedPrinter& printer;

private:
    void CalculateFactorialsMultiThread(const std::vector<unsigned long long>& _numbers);
    void CalculateAndPrintFactorials(const std::vector<unsigned long long>& _numbers);
    std::chrono::milliseconds MeasureExecutionTime(void (PerformanceTester::* _functionToMeasure)(const std::vector<unsigned long long>&), const std::vector<unsigned long long>& _numbers);

public:
    PerformanceTester(ThreadedPrinter& _printer) : printer(_printer) {}

    void Test(const std::vector<unsigned long long>& _numbers);
};