#pragma once
#include "ClientAPI.h"
#include "API_Util.h"

namespace ManaCraft {
	namespace Client {
		class Sprite : public GuiElement
		{
		private:
			int rectWidth;
			int rectHeight;
		public:
			Sprite(SDL_Texture *t, int posX, int posY);
			~Sprite();
			virtual void Update(double time);
			virtual void Draw();
		};
	}
}

