#pragma once
#include "AnimatedSprite.h"
#include "Tower.h"

class GuiTower :
	public AnimatedSprite
{
public:
	SDL_Texture *_texture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	/*GuiTower(Tower _tower)
	{

	}*/
};