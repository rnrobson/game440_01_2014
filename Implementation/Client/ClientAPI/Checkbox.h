#pragma once
#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "GuiElement.h"

class Checkbox :
	public GuiElement
{
private:
	SDL_Texture* outlineLeftRight;
	SDL_Texture* outlineTopBottom;

	int BorderCheckSeperation = 6;
	int BorderWidth = 4;

public:
	Checkbox(SDL_Rect _rect, SDL_Color _checkColour, SDL_Color _outlineColour);
	~Checkbox();

	bool Checked = false;

	virtual void Update(double _time);
	virtual void Draw();

	virtual void OnMouseClick();
	virtual void OnMouseDown(SDL_MouseButtonEvent e);
	virtual void OnMouseUp(SDL_MouseButtonEvent e);

};

#endif
