#pragma once
#include "AnimatedSprite.h"
#include "Tower.h"

namespace ManaCraft {
	namespace Client {
		class GuiTower :
			public AnimatedSprite
		{
		public:
			SDL_Renderer *_renderer;
			GridSquare gridSquare;

			GuiTower(Tower _tower)
				: AnimatedSprite(ClientAPI::GetTexture("TowerTex"), _renderer, gridSquare.xPos, gridSquare.yPos)
			{
			}
		};
	}
}