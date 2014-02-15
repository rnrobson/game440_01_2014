#pragma once

#include <list>

#include "GridNode.h"
#include "AssetSquare.h"

class MinionPath //Path is a reserved class name
{
private:
	std::list<GridNode> nodes;
	AssetSquare* origin; //not sure if this is correct

public:
	char id;
	unsigned int spawnerID;

	MinionPath(void);
	~MinionPath(void);
};

