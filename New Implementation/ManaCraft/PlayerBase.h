#pragma once
#ifndef PLAYER_BASE_H
#define PLAYER_BASE_H

#include <SDL.h> //included for SDL_Rect

typedef unsigned int uint;

class PlayerBase
{

public:
	int xPos;
	int yPos;
	
	int health;

	SDL_Rect* collisionBox;
	uint colWidth;
	uint colHeight;

	PlayerBase(int _xPos, int _yPos, int _health, uint _colWidth, uint _colHeight);
	~PlayerBase();
			
	void TakeDamage(uint damage);

};

#endif