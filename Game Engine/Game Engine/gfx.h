#ifndef GFX_H
#define GFX_H

#include <SDL.h>
#include <iostream>
#include "color.h"

class Gfx
{
public:
	Gfx();
	~Gfx();
	bool IsInitialised();
	Color GetColor();
	void SetColor(float red, float green, float blue, float alpha = 1.F);
	void Clear();
	void Update();

private:
	SDL_Window *mainWindow;
	SDL_Renderer *renderer;
	bool isInitialised;
	Color *color;
};

#endif