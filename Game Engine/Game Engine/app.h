#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <iostream>
#include "gfx.h"
#include "gameObject.h"
#include "list.h"

class App
{
public:
	App();
	~App();
	void Run();
	void AddObject(GameObject *object);

private:
	Gfx* gfx;
	List<GameObject*>* objects;

	void Input();
	void Update();
	void Render();
	void Quit();
};

#endif