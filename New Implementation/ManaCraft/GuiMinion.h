#pragma once
#include "AnimatedSprite.h"
#include "Minion.h"

class GuiMinion :
	public AnimatedSprite
{
public:
	SDL_Renderer *_renderer;

	GuiMinion(Minion _minion)
		: AnimatedSprite(ClientAPI::GetTexture("MinionTex"), _renderer, _minion.xPos, _minion.yPos)
	{
	}
};

