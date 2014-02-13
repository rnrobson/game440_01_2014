#pragma once

#include "ArtSquare.h"

class AssetSquare : public ArtSquare
{
public:
	char type;
	char team;

	AssetSquare(void);
	~AssetSquare(void);
};

