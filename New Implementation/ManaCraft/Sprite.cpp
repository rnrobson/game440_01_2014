#include "Sprite.h"


Sprite::Sprite(SDL_Texture *tex, int posX,int posY)
	:GuiElement(tex, { 0, 0, 0, 0 })
{
	SDL_QueryTexture(tex, NULL, NULL, &rectWidth, &rectHeight);
	GuiElement::SetPosition(posX, posY);
	GuiElement::SetWidthHeight(rectWidth, rectHeight);
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
{
	GuiElement::Draw();
}
