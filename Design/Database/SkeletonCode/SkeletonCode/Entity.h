#pragma once
#include <string>

#include "Element.h"

class Entity
{
private:
	Element* element;

public:
	std::string name;
	unsigned int level;
	unsigned int damage;
	unsigned int summonCost;
	unsigned int upgradeCost;
	unsigned int researchCost;

	Entity(void);
	~Entity(void);
};

