#ifndef GFX_H
#define GFX_H

#include <SDL.h>
#include <iostream>
#include <string>
#include "color.h"
#include "timer.h"

class Gfx
{
public:
	Gfx(int windowWidth, int windowHeight, std::string caption = "Application");
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
	void SetWindowSize(int width, int height);
	void GetWindowSize(int* width, int* height);
	void CenterWindow();
	void GetWindowPos(int* x, int* y);
	void SetWindowPos(int x, int y);
	std::string GetWindowTitle();
	void SetWindowTitle(std::string title);

private:
	SDL_Window *mainWindow;
	SDL_Renderer *renderer;
	bool isInitialised;
	Color *color;
	Timer* fpsTimer;

	void WorldToPixels(float x, float y, int *pixelX, int *pixelY);
};

#endif