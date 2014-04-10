#pragma once

#include <vector>
#include <string>

#include "GridLayer.h"
#include "MinionPath.h"
#include "NavMap.h"
#include "Vec3f.h"

class Level
{
private:
	GridLayer artLayer;
	GridLayer assetLayer;
	GridLayer infLayer;
	//std::vector<MinionPath> paths;
	NavMap navPathTop;
	NavMap navPathMid;
	NavMap navPathBottom;

public:
	std::string name;
	unsigned int width;
	unsigned int height;

	Level(void);
	~Level(void);
};

