#include "PlayerBase.h"

PlayerBase::PlayerBase(int _xPos, int _yPos, int _health, uint _colWidth, uint _colHeight)
{
	xPos = _xPos;
	yPos = _yPos;
	health = _health;
	colWidth = _colWidth;
	colHeight = _colHeight;
	collisionBox = new SDL_Rect();
	collisionBox->x = xPos;// -colWidth / 2;
	collisionBox->y = yPos;// -colHeight / 2;
	collisionBox->w = colWidth;
	collisionBox->h = colHeight;
}
PlayerBase::~PlayerBase(){}

void PlayerBase::TakeDamage(uint damage)
{
	health -= damage;
}
