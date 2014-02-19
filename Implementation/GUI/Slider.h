#pragma once
#include "GuiElement.h"
class GUI_API Slider
	:public GuiElement
{
private:
	SDL_Texture* slider;
	SDL_Rect sliderRect;
public: 

	Slider(SDL_Rect _rect, SDL_Texture* _sliderBar, SDL_Texture* _slider);
	~Slider();

	virtual void Update(double _time);
	virtual void Draw();

	int Value()
	{
		int value = sliderRect.x - rect.x;
		return value;
	}

	virtual void OnMouseDown(SDL_MouseButtonEvent e);
	virtual void OnMouseUp(SDL_MouseButtonEvent e);
};

