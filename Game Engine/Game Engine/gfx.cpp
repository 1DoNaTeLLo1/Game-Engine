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
	this->fpsTimer = new Timer();
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

void Gfx::DrawPoint(float x, float y)
{
	int pixelX, pixelY;
	WorldToPixels(x, y, &pixelX, &pixelY);

	SDL_SetRenderDrawColor(this->renderer, this->color->GetRedInt(), this->color->GetGreenInt(), this->color->GetBlueInt(), this->color->GetAlphaInt());
	SDL_RenderDrawPoint(this->renderer, pixelX, pixelY);
}

void Gfx::DrawLine(float x0, float y0, float x1, float y1)
{
	int pixelX0, pixelY0, pixelX1, pixelY1;
	this->WorldToPixels(x0, y0, &pixelX0, &pixelY0);
	this->WorldToPixels(x1, y1, &pixelX1, &pixelY1);

	SDL_SetRenderDrawColor(this->renderer, this->color->GetRedInt(), this->color->GetGreenInt(), this->color->GetBlueInt(), this->color->GetAlphaInt());
	SDL_RenderDrawLine(this->renderer, pixelX0, pixelY0, pixelX1, pixelY1);
}

void Gfx::DrawRect(float x, float y, float width, float height)
{
	int pixelX, pixelY, pixelWidth, pixelHeight;
	this->WorldToPixels(x, y, &pixelX, &pixelY);
	this->WorldToPixels(width, height, &pixelWidth, &pixelHeight);

	SDL_Rect rect;
	rect.x = pixelX;
	rect.y = pixelY;
	rect.w = pixelWidth;
	rect.h = pixelHeight;

	SDL_SetRenderDrawColor(this->renderer, this->color->GetRedInt(), this->color->GetGreenInt(), this->color->GetBlueInt(), this->color->GetAlphaInt());
	SDL_RenderDrawRect(this->renderer, &rect);
}

void Gfx::DrawFillRect(float x, float y, float width, float height)
{
	int pixelX, pixelY, pixelWidth, pixelHeight;
	this->WorldToPixels(x, y, &pixelX, &pixelY);
	this->WorldToPixels(width, height, &pixelWidth, &pixelHeight);

	SDL_Rect rect;
	rect.x = pixelX;
	rect.y = pixelY;
	rect.w = pixelWidth;
	rect.h = pixelHeight;

	SDL_SetRenderDrawColor(this->renderer, this->color->GetRedInt(), this->color->GetGreenInt(), this->color->GetBlueInt(), this->color->GetAlphaInt());
	SDL_RenderFillRect(this->renderer, &rect);
}

float Gfx::Vsync(int fps)
{
	float deltaTime = this->fpsTimer->Tick();
	float expectedDeltaTime = 1.F / (float)fps;

	if (expectedDeltaTime > deltaTime)
	{
		float waitTime = expectedDeltaTime - deltaTime;
		this->Delay(waitTime);
	}

	return expectedDeltaTime;
}

void Gfx::WorldToPixels(float x, float y, int* pixelX, int* pixelY)
{
	int windowWidth, windowHeight;
	SDL_GetWindowSize(this->mainWindow, &windowWidth, &windowHeight);
	windowWidth--;
	windowHeight--;

	*pixelX = (int)(x * (float)windowWidth);
	*pixelY = (int)(y * (float)windowHeight);
}

void Gfx::Delay(float seconds)
{
	Timer* timer = new Timer();
	float passedTime = 0.F;

	while (passedTime < seconds)
	{
		passedTime += timer->Tick();
	}

	delete timer;
	timer = nullptr;
}