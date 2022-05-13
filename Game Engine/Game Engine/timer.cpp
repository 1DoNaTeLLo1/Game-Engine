#include "timer.h"

Timer::Timer()
{
	this->time = clock();
}

clock_t Timer::Tick()
{
	clock_t now = clock();
	clock_t deltaTime = now - this->time;
	time = now;
	return deltaTime;
}