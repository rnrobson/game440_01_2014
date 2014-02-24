#include "Sprite.h"


Sprite::Sprite(SDL_Texture *tex,SDL_Renderer *renderer,int posX,int posY)
{
	//SDL_RenderClear(renderer);
	//RenderTexture(tex, renderer, posX, posY, nullptr);//for now
	//SDL_RenderPresent(renderer);
}

Sprite::~Sprite()
{
}

void Sprite::RenderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, SDL_Rect *clip=nullptr)
{
	SDL_Rect dst; //destination
	dst.x = x;
	dst.y = y;
	//if clip rect is specified 
	if (clip != nullptr)
	{
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else //if clip rect not specified, renders whole image
	{
		SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	}
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, clip, &dst);
	SDL_RenderPresent(renderer);
}
