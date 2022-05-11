#include "app.h"

App::App()
{
	this->gfx = new Gfx();

	if (this->gfx == nullptr || !this->gfx->IsInitialised())
	{
		std::cout << "Graphics could not initialize!" << std::endl;
		this->Quit();
	}
}

App::~App()
{
	delete this->gfx;
	this->gfx = nullptr;

	this->Quit();
}

void App::Run()
{
	while (true)
	{
		this->Input();
		this->Update();
		this->Render();
	}
}

void App::Input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			this->Quit();
		}
	}
}

void App::Update()
{

}

void App::Render()
{
	this->gfx->SetColor(0.F, 0.F, 0.F);
	this->gfx->Clear();

	this->gfx->Update();
}

void App::Quit()
{
	SDL_Quit();
	exit(0);
}