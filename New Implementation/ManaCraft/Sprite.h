#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
class Sprite : public GuiElement
{
private:
	int rectWidth;
	int rectHeight;
public:
	Sprite(SDL_Texture *t, int posX, int posY);
	~Sprite();
	void RenderTexture(SDL_Texture *t,SDL_Renderer *r,int x,int y,SDL_Rect *clip);

};

