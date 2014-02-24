#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
class Sprite
{
public:
	Sprite(SDL_Texture *t,SDL_Renderer *r,int posX, int posY);
	virtual ~Sprite();
	void RenderTexture(SDL_Texture *t,SDL_Renderer *r,int x,int y,SDL_Rect *clip);

};

