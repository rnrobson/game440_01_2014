#pragma once

#include "Tower.h"
#include "Minion.h"

class Projectile
{
private:
	Tower* origin;
	Minion* target;

public:
	float xPos;
	float yPos;

	Projectile(void);
	~Projectile(void);
};

