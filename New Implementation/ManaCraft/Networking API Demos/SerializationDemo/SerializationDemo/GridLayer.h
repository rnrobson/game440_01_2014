#pragma once
#include <vector>

class GridLayer
{
public:
	char tileSize;
	unsigned int rows;
	unsigned int columns;

	GridLayer(void);
	~GridLayer(void);
};

