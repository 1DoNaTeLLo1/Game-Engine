#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <iostream>
#include "gfx.h"

class App
{
public:
	App();
	~App();
	void Run();
	void Quit();

private:
	Gfx* gfx;
};

#endif