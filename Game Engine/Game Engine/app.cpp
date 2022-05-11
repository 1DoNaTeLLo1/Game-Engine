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
		SDL_Event e;
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				this->Quit();
			}
		}

		//Clear screen
		this->gfx->SetColor(0.F, 0.F, 0.F);
		this->gfx->Clear();

		//Update screen
		this->gfx->Update();
	}
}

void App::Quit()
{
	//Quit SDL subsystems
	SDL_Quit();
	exit(0);
}