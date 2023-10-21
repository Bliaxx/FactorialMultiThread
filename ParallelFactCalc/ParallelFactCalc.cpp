#include "PerformanceTester.h"

int main()
{
    ThreadedPrinter _printer;
    std::vector<unsigned long long> _numbers = { 5, 10, 15, 20, 25, 30, 35, 40 };

    PerformanceTester _tester(_printer);
    _tester.Test(_numbers);
    return 0;
}
