#pragma once
#include "Entity.h"
#include "InfluenceSquare.h"

class Tower : public Entity
{
private:
	InfluenceSquare* infSquare;

public:
	unsigned int range;
	float firingRate;
	float damagePerSecond;
	char attackType;
	unsigned int sellAmount;
	char zoneOfInfluence;

	Tower(void);
	~Tower(void);
};

