#include "AnimatedSprite.h"

const int NUMFRAMES = 16;//minion spritesheets have 4 rows and 4 columns
int columns = 4;

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
	width /= NUMFRAMES; //width of each frame
	for (int i = 0; i < NUMFRAMES; i++)
	{
		row = 1;
		clips[i].x = i*width;
		clips[i].y = row*height;
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
	row = LEFT;
	currentFrame = row * columns;
}
void AnimatedSprite::Right()
{
	row = RIGHT;
	currentFrame = row * columns;
}
void AnimatedSprite::Up()
{
	row = UP;
	currentFrame = row * columns;
}
void AnimatedSprite::Down()
{
	row = DOWN;
	currentFrame = row * columns;
}
void AnimatedSprite::Update()
{
	timeElapsed = SDL_GetTicks();
	if (timeElapsed - lastUpdated >= 83)//about 12 frames/second 1000ms/12frames=83.3
	{
		Sprite::RenderTexture(sheet, ren, x, y, &clips[currentFrame]);
		if (row = LEFT)
		{
			if (currentFrame == (row * columns) + columns - 1)//when left animation reaches last frame, set animation back to first frame
				currentFrame = row * columns;
		}
		else if (row = RIGHT)
		{
			if (currentFrame == (row * columns) + columns - 1)
				currentFrame = row * columns;
		}
		else if (row = UP)
		{
			if (currentFrame == (row * columns) + columns - 1)
				currentFrame = row * columns;
		}
		else if (row = DOWN)
		{
			if (currentFrame == (row * columns) + columns - 1)
				currentFrame = row * columns;
		}
		
		currentFrame++;
		lastUpdated = timeElapsed;
	}
}