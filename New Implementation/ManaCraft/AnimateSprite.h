#pragma once
#include "Sprite.h"
class AnimateSprite :
	public Sprite
{
public:
	
	AnimateSprite(SDL_Texture *t, SDL_Renderer *r, int posX, int posY);
	~AnimateSprite();
	void Left();
	void Right();
	void Up();
	void Down();
	void Update();
private:

	int width;
	int height;
	int lastUpdated;
	int timeElapsed;
	int currentFrame;

	bool left;
	bool right;
	bool up;
	bool down;

	SDL_Texture *sheet;
	SDL_Renderer *ren;

	int x;
	int y;
};

