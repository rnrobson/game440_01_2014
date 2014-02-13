#pragma once
#ifndef LABEL_H
#define LABEL_H

#include "GuiElement.h"

class Label :
	public GuiElement
{
public:
	Label(const std::string &_text, SDL_Rect _rect, TTF_Font* _font, SDL_Color _color);
	~Label();

	virtual void RenderText();
	virtual void RenderText(std::string &_text);

	virtual void Update(double _time);
	virtual void Draw();

	virtual void Clear();

	std::string text = "";
	SDL_Color fontColor;
	TTF_Font *font;
};
#endif