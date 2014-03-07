#pragma once

#include "Element.h"

class Entity
{
private:

public:
	ManaCraft::Database::ElementTypes elementID;

	std::string name;
	unsigned int damage;
	unsigned int level;
	unsigned int cost;
	unsigned int summonCost;
	unsigned int upgradeCost;
	unsigned int researchCost;
	

	Entity(void);
	~Entity(void);
};

