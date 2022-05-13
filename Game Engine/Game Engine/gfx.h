#ifndef GFX_H
#define GFX_H

#include <SDL.h>
#include <iostream>
#include "color.h"
#include "timer.h"

class Gfx
{
public:
	Gfx(int windowWidth, int windowHeight);
	~Gfx();
	bool IsInitialised();
	Color GetColor();
	void SetColor(float red, float green, float blue, float alpha = 1.F);
	void Clear();
	void Update();
	void DrawPoint(float x, float y);
	void DrawLine(float x0, float y0, float x1, float y1);
	void DrawRect(float x, float y, float width, float height);
	void DrawFillRect(float x, float y, float width, float height);
	float Vsync(int fps = 60);

private:
	SDL_Window *mainWindow;
	SDL_Renderer *renderer;
	bool isInitialised;
	Color *color;
	Timer* fpsTimer;

	void WorldToPixels(float x, float y, int *pixelX, int *pixelY);
};

#endif