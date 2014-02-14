#pragma once
#include "Label.h"

class Tooltip :	public Label
{
private:
	SDL_Texture *bgTexture;

public:
	Tooltip(SDL_Texture *_tex, const std::string &_text, SDL_Rect _rect, TTF_Font *_font, SDL_Color _color);
	~Tooltip();

	virtual void Update(double _time);
	virtual void Draw();
};