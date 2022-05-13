#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include "gfx.h"

class GameObject
{
public:
	virtual void Input(SDL_Event *e);
	virtual void Update(float deltaTime);
	virtual void Render(Gfx* gfx);
};

#endif