#include "FactorialCalculator.h"

void FactorialCalculator::Calculate()
{
    result = 1;
    for (unsigned long long i = 1; i <= n; ++i) {
        result *= i;
    }
}
