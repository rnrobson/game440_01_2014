#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "GuiElement.h"
#include "Label.h"

class GUI_API Button
	:public GuiElement
{
private:
	SDL_Texture* downTexture;
	SDL_Texture* hoverTexture;
	SDL_Texture* disabledTexture;

	Label* label = nullptr;

	bool isPressedDown = false;
	bool isHovering = false;

	void LoadButtonTextures(SDL_Rect _rect);

public:
	//Button();
	Button(SDL_Texture* _tex, SDL_Rect _rect);
	Button(SDL_Rect _rect);
	~Button();

	void AddLabel(const std::string &_text, TTF_Font* _font, SDL_Color _color, bool center = false);
	void AddLabel(Label* _label);
	Label* GetLabel();

	virtual void SetOffset(SDL_Rect _rect);
	virtual void SetPadding(SDL_Rect _rect);

	virtual void Update(double _time);
	virtual void Draw();

	virtual void OnMouseHover(SDL_MouseMotionEvent e);
	virtual void OnMouseClick();
	virtual void OnMouseDown(SDL_MouseButtonEvent e);
	virtual void OnMouseUp(SDL_MouseButtonEvent e);

};

#endif
