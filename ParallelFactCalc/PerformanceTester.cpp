#include "PerformanceTester.h"

void PerformanceTester::CalculateFactorialsMultiThread(const std::vector<unsigned long long>& _numbers)
{
    std::vector<std::thread> _threads;
    for (auto _n : _numbers) {
        ThreadedTask _task(_n, printer);
        _threads.push_back(std::thread(_task));
    }

    for (auto& _t : _threads) {
        _t.join();
    }
}

void PerformanceTester::CalculateAndPrintFactorials(const std::vector<unsigned long long>& _numbers)
{
    for (auto _n : _numbers) {
        FactorialCalculator _calculator(_n);
        _calculator.Calculate();
        printer.Print(_n, _calculator.GetResult());
    }
}

std::chrono::milliseconds PerformanceTester::MeasureExecutionTime(void(PerformanceTester::* _functionToMeasure)(const std::vector<unsigned long long>&), const std::vector<unsigned long long>& _numbers)
{
    auto _start = std::chrono::high_resolution_clock::now();
    (this->*_functionToMeasure)(_numbers);
    auto _end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start);
}

void PerformanceTester::Test(const std::vector<unsigned long long>& _numbers)
{
    auto _durationMonoThread = MeasureExecutionTime(&PerformanceTester::CalculateAndPrintFactorials, _numbers);
    auto _durationMultiThread = MeasureExecutionTime(&PerformanceTester::CalculateFactorialsMultiThread, _numbers);

    std::cout << "Mono-threaded time: " << _durationMonoThread.count() << "ms" << std::endl;
    std::cout << "Multi-threaded time: " << _durationMultiThread.count() << "ms" << std::endl;
}
