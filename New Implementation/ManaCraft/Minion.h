#pragma once
#include "Entity.h"
#include "Resistances.h"

class Minion : public Entity
{
private:
	Resistances* res; //not sure if this is correct

public:
	float health;
	float xPos;
	float yPos;
	float manaPerSecond;
	unsigned int armour;
	unsigned int speed;

	Minion(void);
	~Minion(void);
};

