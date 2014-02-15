#pragma once

#include "GridLayer.h"
#include "InfluenceSquare.h"

class InfluenceLayer : public GridLayer
{
private:
	std::vector<InfluenceSquare> infSquares;

public:
	InfluenceLayer(void);
	~InfluenceLayer(void);
};

