#include "gfx.h"

Gfx::Gfx(int windowWidth, int windowHeight)
{
	this->isInitialised = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
		this->isInitialised = false;
	}

	this->mainWindow = SDL_CreateWindow("Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (this->mainWindow == NULL)
	{
		std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
		this->isInitialised = false;
	}

	this->renderer = SDL_CreateRenderer(this->mainWindow, -1, SDL_RENDERER_ACCELERATED);
	if (this->renderer == NULL)
	{
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
		this->isInitialised = false;
	}

	this->color = new Color();
}

Gfx::~Gfx()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->mainWindow);
	this->mainWindow = nullptr;
	this->renderer = nullptr;

	delete this->color;
	this->color = nullptr;
}

bool Gfx::IsInitialised()
{
	return this->isInitialised;
}

Color Gfx::GetColor()
{
	return *this->color;
}

void Gfx::SetColor(float red, float green, float blue, float alpha)
{
	this->color->SetRed(red);
	this->color->SetGreen(green);
	this->color->SetBlue(blue);
	this->color->SetAlpha(alpha);
}

void Gfx::Clear()
{
	SDL_SetRenderDrawColor(this->renderer, this->color->GetRedInt(), this->color->GetGreenInt(), this->color->GetBlueInt(), this->color->GetAlphaInt());
	SDL_RenderClear(this->renderer);
}

void Gfx::Update()
{
	SDL_RenderPresent(this->renderer);
}