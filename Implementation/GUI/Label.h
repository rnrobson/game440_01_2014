#pragma once
#ifndef LABEL_H
#define LABEL_H

#include "GuiElement.h"

class GUI_API Label
	:public GuiElement
{
public:
	Label(const std::string &_text, SDL_Rect _rect, TTF_Font* _font, SDL_Color _color);
	~Label();

	void RenderText();
	void RenderText(std::string &_text);

	virtual void Update(double _time);
	virtual void Draw();

	std::string text = "";
	SDL_Color fontColor;
	TTF_Font *font;
};
#endif