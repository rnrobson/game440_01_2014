#pragma once

#include "GridLayer.h"
#include "ArtSquare.h"

class ArtLayer : public GridLayer
{
private:
	std::vector<ArtSquare> artSquares;

public:
	ArtLayer(void);
	~ArtLayer(void);
};

