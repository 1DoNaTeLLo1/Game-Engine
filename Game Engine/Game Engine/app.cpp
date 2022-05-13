#include "app.h"

App::App()
{
	this->gfx = new Gfx(500, 500);

	if (this->gfx == nullptr || !this->gfx->IsInitialised())
	{
		std::cout << "Graphics could not be initialised!" << std::endl;
		this->Quit();
	}

	this->objects = new Dict<std::string, GameObject*>();
}

App::~App()
{
	delete this->gfx;
	this->gfx = nullptr;

	for (int i = 0; i < this->objects->Size(); i++)
	{
		GameObject* object = this->objects->Get(i);
		delete object;
		object = nullptr;
	}

	delete this->objects;
	this->objects = nullptr;

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

void App::AddObject(std::string name, GameObject* object)
{
	this->objects->Insert(name, object);
}

void App::Input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		for (int i = 0; i < this->objects->Size(); i++)
		{
			this->objects->Get(i)->Input(&e);
		}

		if (e.type == SDL_QUIT)
		{
			this->Quit();
		}
	}
}

void App::Update()
{
	float deltaTime =  this->gfx->Vsync();

	for (int i = 0; i < this->objects->Size(); i++)
	{
		this->objects->Get(i)->Update(deltaTime);
	}
}

void App::Render()
{
	this->gfx->SetColor(0.F, 0.F, 0.F);
	this->gfx->Clear();

	for (int i = 0; i < this->objects->Size(); i++)
	{
		this->objects->Get(i)->Render(this->gfx);
	}

	this->gfx->Update();
}

void App::Quit()
{
	SDL_Quit();
	exit(0);
}