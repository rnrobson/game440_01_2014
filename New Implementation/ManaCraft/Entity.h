#pragma once

#include "Element.h"

class Entity
{
private:
	Element* element;

public:
	std::string name;
	float damage;
	unsigned int level;
	unsigned int summonCost;
	unsigned int upgradeCost;
	unsigned int researchCost;
	

	Entity(void);
	~Entity(void);
};

