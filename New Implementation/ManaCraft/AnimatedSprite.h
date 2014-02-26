#pragma once
#include "Sprite.h"
class AnimatedSprite :
	public Sprite
{
public:
	
	AnimatedSprite(SDL_Texture *t, SDL_Renderer *r, int posX, int posY);
	~AnimatedSprite();
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
	int direction;

	enum Direction { DOWN, LEFT, UP, RIGHT };

	SDL_Texture *sheet;
	SDL_Renderer *ren;

	int x;
	int y;
};

