#pragma once
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

//#include "ClientAPI.h"
//#include "Includes.h"
//#include <SDL.h>
#include "Window.h"

class GuiElement
{
protected:
	SDL_Texture *texture;
	SDL_Rect rect;
	SDL_Rect offset;
	SDL_RendererFlip flip;
public:
	GuiElement()
	{
		texture = nullptr;
		rect = { 0, 0, 0, 0 };
		offset = { 0, 0, 0, 0 };
	}
	GuiElement(SDL_Texture *_texture, SDL_Rect _rect)
	{
		texture = _texture;
		rect = _rect;
		offset = { 0, 0, 0, 0 };
	}
	~GuiElement() { Free(); }
	virtual void Update(double _time) { if (Active) { } }

	virtual void Draw()
	{
		if (Active) {
			SDL_Rect rectangle = rect;
			rectangle.x += offset.x;
			rectangle.y += offset.y;

			SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rectangle, 0, NULL, flip); //SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rect, 0, NULL, flip);
		}
	}

	bool Intersects(SDL_Rect _rect)
	{
		if (SDL_HasIntersection(&rect, &_rect) == SDL_TRUE)
		{
			return true;
		}
		else if (SDL_HasIntersection(&rect, &_rect) == SDL_FALSE)
		{
			return false;
		}
	}

	virtual void Free()
	{
		if (texture != NULL)
		{
			SDL_DestroyTexture(texture);
			texture = NULL;
			rect.w = rect.h = 0;
		}

		delete &rect;
		delete &flip;
	}

	bool Active = true;

	int GetHeight() { return rect.h; }
	int GetWidth() { return rect.w; }
	int GetX() { return rect.x; }
	int GetY() { return rect.y; }

	void SetPosition(int _x, int _y)
	{
		rect.x = _x;
		rect.y = _y;
	}

	void SetWidthHeight(int _w, int _h)
	{
		rect.w = _w;
		rect.h = _h;
	}

	void SetScale(int _xScale, int _yScale)
	{
		rect.w *= _xScale;
		rect.h *= _yScale;
	}

	SDL_Rect GetOffset() { return offset; }
	void SetOffset(SDL_Rect _rect){ offset = _rect; }
};
#endif


