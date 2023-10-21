#include "ThreadedTask.h"

void ThreadedTask::operator()()
{
	calculator.Calculate();
	printer.Print(calculator.GetN(), calculator.GetResult());
}
