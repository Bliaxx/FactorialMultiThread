#include "ThreadedPrinter.h"

void ThreadedPrinter::Print(unsigned long long _n, unsigned long long _result)
{
    std::lock_guard<std::mutex> _lock(mtx);
    std::cout << "Factorial of " << _n << " is: " << _result << std::endl;
}