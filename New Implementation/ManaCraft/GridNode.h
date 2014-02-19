#pragma once
#include "GridSquare.h"

class GridNode : public GridSquare
{
public:
	char nodeID;
	char pathID;
	GridNode* next;

	GridNode(void);
	~GridNode(void);
};

