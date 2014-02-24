#pragma once

#include <vector>
#include <string>

#include "GridLayer.h"
#include "MinionPath.h"

class Level
{
private:
	GridLayer artLayer;
	GridLayer assetLayer;
	GridLayer infLayer;
	std::vector<MinionPath> paths;

public:
	std::string name;
	unsigned int width;
	unsigned int height;

	Level(void);
	~Level(void);
};

