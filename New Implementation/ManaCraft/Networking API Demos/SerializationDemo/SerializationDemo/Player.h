#pragma once

#include <list>

#include "Entity.h"
#include "InfluenceSquare.h"

class Player
{
private:
	std::list<Entity*> towers;
	std::list<Entity*> minions;
	std::list<InfluenceSquare*> infSquares; //the diagram says Player has an Influence Square
											//I'm guessing it's supposed to be a list of Influence Squares?
public:
	unsigned int mana;
	unsigned int totalManaPerSecond;
	char teamID;

	Player(void);
	~Player(void);
};

