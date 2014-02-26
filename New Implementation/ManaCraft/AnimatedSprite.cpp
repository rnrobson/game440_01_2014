#include "AnimatedSprite.h"

const int NUMFRAMES = 16;//minion spritesheets have 4 rows and 4 columns

SDL_Rect clips[NUMFRAMES];

AnimatedSprite::AnimatedSprite(SDL_Texture *tex, SDL_Renderer *renderer, int posX, int posY) 
	:Sprite(tex,renderer,posX,posY)
{
	SDL_QueryTexture(tex, NULL, NULL, &width, &height);
	
	sheet = tex;
	ren = renderer;
	x = posX;
	y = posY;

	//only animating minions
	width = width / NUMFRAMES; //width of each frame
	for (int i = 0; i < NUMFRAMES; i++)
	{
		clips[i].x = i*width;
		clips[i].y = 0;
		clips[i].w = width;
		clips[i].h = height;
	}
	currentFrame = 0;
	lastUpdated = SDL_GetTicks();
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::Left()
{
	currentFrame = 4; //first frame of left animation
	direction = LEFT;
}
void AnimatedSprite::Right()
{
	currentFrame = 12;
	direction = RIGHT;
}
void AnimatedSprite::Up()
{
	currentFrame = 8;
	direction = UP;
}
void AnimatedSprite::Down()
{
	currentFrame = 0;
	direction = DOWN;
}
void AnimatedSprite::Update()
{
	timeElapsed = SDL_GetTicks();
	if (timeElapsed - lastUpdated >= 83)//about 12 frames/second 1000ms/12frames=83.3
	{
		Sprite::RenderTexture(sheet, ren, x, y, &clips[currentFrame]);
		if (direction = LEFT)
		{
			if (currentFrame == 7)//when left animation reaches last frame, set animation back to first frame
				currentFrame = 4;
		}
		else if (direction = RIGHT)
		{
			if (currentFrame == 15)
				currentFrame = 12;
		}
		else if (direction = UP)
		{
			if (currentFrame == 11)
				currentFrame = 8;
		}
		else if (direction = DOWN)
		{
			if (currentFrame == 3)
				currentFrame = 0;
		}
		
		currentFrame++;
		lastUpdated = timeElapsed;
	}
}