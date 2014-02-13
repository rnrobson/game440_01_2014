#include "Slider.h"


Slider::Slider(SDL_Rect _rect, SDL_Texture* _sliderBar, SDL_Texture* _slider)
:GuiElement(_sliderBar, _rect)
{
	slider = _slider;
	sliderRect = { _rect.x + _rect.w, _rect.y, 10, _rect.h + 20 };
}


Slider::~Slider()
{
	SDL_DestroyTexture(slider);

	GuiElement::~GuiElement();
}

void Slider::Update(double _time)
{
	if (Active) {
		if (Enabled) {
			GuiElement::Update(_time);
		}
	}
}

void Slider::Draw()
{
	if (Active){
		SDL_RenderCopyEx(Window::Renderer(), slider, NULL, &rect, 0, NULL, flip);

		GuiElement::Draw();
	}
}

void Slider::OnMouseDown(SDL_MouseButtonEvent e)
{
	GuiElement::OnMouseDown(e);
}
void Slider::OnMouseUp(SDL_MouseButtonEvent e)
{
	GuiElement::OnMouseUp(e);
}