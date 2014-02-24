#pragma once
#include "GridSquare.h"

class ArtSquare : public GridSquare
{
public:
	char spriteID; //Should be pointer to texture Image

	ArtSquare(void);
	~ArtSquare(void);
};

