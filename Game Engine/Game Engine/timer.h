#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer
{
public:
	Timer();
	float Tick();

private:
	clock_t time;
};

#endif