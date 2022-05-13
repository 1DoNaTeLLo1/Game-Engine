#include "timer.h"

Timer::Timer()
{
	this->time = clock();
}

float Timer::Tick()
{
	clock_t now = clock();
	clock_t deltaTime = now - this->time;
	time = now;
	return (float)deltaTime / (float)CLOCKS_PER_SEC;
}