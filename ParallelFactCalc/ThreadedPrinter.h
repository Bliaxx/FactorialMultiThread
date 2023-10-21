#pragma once
#include "FactorialCalculator.h"
#include <mutex>

class ThreadedPrinter
{
private:
	std::mutex mtx;

public:
	void Print(unsigned long long _n, unsigned long long _result);
};

