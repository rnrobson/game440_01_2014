#pragma once
#include "GridSquare.h"

class InfluenceSquare : public GridSquare
{
public:
	int influenceLevel;

	InfluenceSquare(void);
	~InfluenceSquare(void);
};

