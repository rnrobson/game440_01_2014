#include "Button.h"

void Button::LoadButtonTextures(SDL_Rect _rect)
{
	//-- Down Texture
	Button::downTexture = APIHelper::SolidColourTexture(_rect.w, _rect.h, { 0, 0, 0, 155 });

	//-- Hover Texture
	Button::hoverTexture = APIHelper::SolidColourTexture(_rect.w, _rect.h, { 255, 255, 255, 155 });

	//-- Disabled Textures
	Button::disabledTexture = APIHelper::SolidColourTexture(_rect.w, _rect.h, { 255, 0, 0, 155 });
}

Button::Button(SDL_Texture* _tex, SDL_Rect _rect)
:GuiElement(_tex, _rect)
{
	LoadButtonTextures(_rect);
}

Button::Button(SDL_Rect _rect)
:GuiElement(nullptr, _rect)
{
	LoadButtonTextures(_rect);

	//-- Regular Texture
	Button::texture = APIHelper::SolidColourTexture(_rect.w, _rect.h, { 0, 0, 0, 255 });
}

Button::~Button()
{
	if (label != nullptr)
		delete label;

	SDL_DestroyTexture(downTexture);
	SDL_DestroyTexture(hoverTexture);

	GuiElement::~GuiElement();
}

void Button::AddLabel(const std::string &_text, TTF_Font* _font, SDL_Color _color, bool center)
{
	SDL_Rect _rect = rect;
	_rect.x += 5;
	_rect.w -= (_rect.x - rect.x);

	if (center) {
		int* w = new int();
		int* h = new int();
		TTF_SizeText(_font, _text.c_str(), w, h);

		_rect.y += ((_rect.h - *h) / 6);
		_rect.h -= (_rect.y - rect.y);
	}

	label = new Label(_text, _rect, _font, _color);
	label->SetOffset(offset);
}
void Button::AddLabel(Label* _label)
{
	label = _label;
	label->SetOffset(offset);
}

Label* Button::GetLabel()
{
	if (label == nullptr)
		return nullptr;
	return label;
}

void Button::SetOffset(SDL_Rect _rect)
{
	GuiElement::SetOffset(_rect);
	if (label != nullptr)
		label->SetOffset(_rect);
}

void Button::SetPadding(SDL_Rect _rect)
{
	GuiElement::SetPadding(_rect);
	if (label != nullptr)
		label->SetPadding(_rect);
}

void Button::Update(double _time)
{
	if (Active) {
		if (Enabled) {
			GuiElement::Update(_time);
		}
	}
}

void Button::Draw()
{
	if (Active) {
		GuiElement::Draw();

		if (label != nullptr)
			label->Draw();

		if (isPressedDown) {
			SDL_Rect rectangle = rect;
			rectangle.x += offset.x + padding.x;
			rectangle.y += offset.y + padding.y;

			SDL_RenderCopyEx(Window::Renderer(), downTexture, NULL, &rectangle, 0., NULL, flip);
		}
		else if (isHovering) {
			SDL_Rect rectangle = rect;
			rectangle.x += offset.x + padding.x;
			rectangle.y += offset.y + padding.y;

			SDL_RenderCopyEx(Window::Renderer(), hoverTexture, NULL, &rectangle, 0., NULL, flip);
		}

		if (!Enabled)
		{
			SDL_Rect rectangle = rect;
			rectangle.x += offset.x + padding.x;
			rectangle.y += offset.y + padding.y;

			SDL_RenderCopyEx(Window::Renderer(), disabledTexture, NULL, &rectangle, 0., NULL, flip);
		}
	}
}

void Button::OnMouseHover(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	if (Intersects({ e.x, e.y, 1, 1 }))
	{
		isHovering = true;
		GuiElement::OnMouseHover(e);
	}
	else isHovering = false;
}
void Button::OnMouseClick()
{
	if (!Active) return;
	if (!Enabled) return;
	if (!isPressedDown) return;

	if (Intersects(APIEvents::MousePosition)) {}
	GuiElement::OnMouseClick();
	
	
}
void Button::OnMouseDown(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	isPressedDown = true;
	GuiElement::OnMouseDown(e);
}
void Button::OnMouseUp(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	isPressedDown = false;
	GuiElement::OnMouseUp(e);
}