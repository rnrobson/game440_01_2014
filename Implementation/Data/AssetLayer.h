#pragma once

#include "GridLayer.h"
#include "AssetSquare.h"

class AssetLayer : public GridLayer
{
private:
	std::vector<AssetSquare> assetSquares;

public:
	AssetLayer(void);
	~AssetLayer(void);
};

