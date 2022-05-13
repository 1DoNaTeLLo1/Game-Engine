#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "gfx.h"
#include "gameObject.h"
#include "dict.h"

class App
{
public:
	App();
	~App();
	void Run();
	void AddObject(std::string name, GameObject *object);

private:
	Gfx* gfx;
	Dict<std::string, GameObject*>* objects;

	void Input();
	void Update();
	void Render();
	void Quit();
};

#endif