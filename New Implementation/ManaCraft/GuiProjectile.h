#pragma once
#include "AnimatedSprite.h"
#include "Projectile.h"

namespace ManaCraft {
	namespace Client {
		class GuiProjectile :
			public AnimatedSprite
		{
		public:
			SDL_Renderer *_renderer;

			GuiProjectile(Projectile _projectile)
				: AnimatedSprite(ClientAPI::GetTexture("ProjectileTex"), _renderer, _projectile.xPos, _projectile.yPos)
			{
			}
		};
	}
}