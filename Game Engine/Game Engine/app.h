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

private:
	Gfx* gfx;

	void Input();
	void Update();
	void Render();
	void Quit();
};

#endif