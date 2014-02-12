#pragma once
#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "Label.h"

class TextField :
	public Label
{
private:
	SDL_Texture* backgroundTexture;
public:
	TextField(SDL_Rect _rect, TTF_Font* _font, SDL_Color _textColour);
	~TextField();

	void AddToString(char _added);
	void RemoveLastCharacterFromString();
	int GetStringSize();
	string GetText();

	virtual void Update(double _time);
	virtual void Draw();

	virtual void OnEnterKeyPressed();
	virtual void OnKeyboardDown(SDL_KeyboardEvent e);
	virtual void OnKeyboardUp(SDL_KeyboardEvent e);
	virtual void OnTextInput(SDL_TextInputEvent e);
};
#endif