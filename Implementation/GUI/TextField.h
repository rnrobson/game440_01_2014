#pragma once
#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "Label.h"

class GUI_API TextField
	:public Label
{
private:
	SDL_Texture* backgroundTexture;
public:
	TextField(SDL_Rect _rect, TTF_Font* _font);
	~TextField();

	void AddToString(char _added);
	void RemoveLastCharacterFromString();
	int GetStringSize();
	string GetText();

	virtual void Update(double _time);
	virtual void Draw();
};
#endif