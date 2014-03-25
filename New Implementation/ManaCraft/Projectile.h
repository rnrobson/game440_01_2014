#pragma once

#include "Tower.h"
#include "Minion.h"

class Projectile
{

public:
	SDL_Rect* collisionBox;
	Tower* origin;
	Minion* target;
	float xPos;
	float yPos;
	float xDir;
	float yDir;
	float speed;
	unsigned int colWidth;
	unsigned int colHeight;

	Projectile(void);
	Projectile(Tower* _origin, Minion* _target,float _projectileSpeed);
	~Projectile(void);
};

