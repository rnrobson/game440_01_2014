#pragma once
#include "ClientAPI.h"
#include "AnimatedSprite.h"
#include "Minion.h"

class GuiMinion :
	public AnimatedSprite
{
public:
	SDL_Texture *_texture = APIHelper::LoadPNGTexture("Resources/Sprites/MinionSS.png");
	SDL_Renderer *_renderer;
	
	/*ClientAPI::AddTexture("MinionTex", _texture);

	GuiMinion(Minion _minion)
		: AnimatedSprite(ClientAPI::GetTexture("MinionTex"), _renderer, _minion.xPos, _minion.yPos)
	{

	}*/
};

