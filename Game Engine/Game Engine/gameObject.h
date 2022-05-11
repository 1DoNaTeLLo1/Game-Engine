#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include "gfx.h"

class GameObject
{
public:
	void Input(SDL_Event *e);
	void Update(float deltaTime);
	void Render(Gfx* gfx);
};

#endif