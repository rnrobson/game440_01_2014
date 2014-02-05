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
	SDL_Rect padding;
	SDL_RendererFlip flip;

	static void(*onMouseHoverFunc)(SDL_MouseMotionEvent e);
	static void(*onMouseClickFunc)();
	static void(*onMouseDownFunc)(SDL_MouseButtonEvent e);
	static void(*onMouseUpFunc)(SDL_MouseButtonEvent e);

	static void(*onKeyboardDownFunc)(SDL_KeyboardEvent e);
	static void(*onKeyboardUpFunc)(SDL_KeyboardEvent e);
	static void(*onTextInputFunc)(SDL_TextInputEvent e);
public:
	bool Active = true;

	GuiElement()
	{
		texture = nullptr;
		rect = { 0, 0, 0, 0 };
		offset = { 0, 0, 0, 0 };
		padding = { 0, 0, 0, 0 };

		onMouseHoverFunc = nullptr;
		onMouseClickFunc = nullptr;
		onMouseDownFunc = nullptr;
		onMouseUpFunc = nullptr;

		onKeyboardDownFunc = nullptr;
		onKeyboardUpFunc = nullptr;
		onTextInputFunc = nullptr;
	}
	GuiElement(SDL_Texture *_texture, SDL_Rect _rect)
	{
		texture = _texture;
		rect = _rect;
		offset = { 0, 0, 0, 0 };
		padding = { 0, 0, 0, 0 };

		onMouseHoverFunc = nullptr;
		onMouseClickFunc = nullptr;
		onMouseDownFunc = nullptr;
		onMouseUpFunc = nullptr;

		onKeyboardDownFunc = nullptr;
		onKeyboardUpFunc = nullptr;
		onTextInputFunc = nullptr;
	}
	~GuiElement() { Free(); }
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
		delete &offset;
		delete &padding;
	}

	virtual void Update(double _time) { if (Active) { } }
	virtual void Draw()
	{
		if (Active) {
			SDL_Rect rectangle = rect;
			rectangle.x += offset.x + padding.x;
			rectangle.y += offset.y + padding.y;

			SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rectangle, 0, NULL, flip); //SDL_RenderCopyEx(Window::Renderer(), texture, NULL, &rect, 0, NULL, flip);
		}
	}

	bool Intersects(SDL_Rect _rect)
	{
		SDL_Rect truePosition = rect;
		truePosition.x += offset.x + padding.x;
		truePosition.y += offset.y + padding.y;

		if (SDL_HasIntersection(&truePosition, &_rect) == SDL_TRUE)
		{
			return true;
		}
		else if (SDL_HasIntersection(&truePosition, &_rect) == SDL_FALSE)
		{
			return false;
		}

		return false;
	}

	int GetHeight() { return rect.h; }
	int GetWidth() { return rect.w; }
	int GetX() { return rect.x; }
	int GetY() { return rect.y; }
	SDL_Rect GetPosition() { return rect; }
	SDL_Rect GetOffset() { return offset; }
	SDL_Rect GetPadding() { return padding; }

	void SetPosition(int _x, int _y) { rect.x = _x; rect.y = _y; }
	void SetWidthHeight(int _w, int _h)	{ rect.w = _w; rect.h = _h; }
	void SetScale(int _xScale, int _yScale)	{ rect.w *= _xScale; rect.h *= _yScale; }
	virtual void SetOffset(SDL_Rect _rect){ offset = _rect; }
	virtual void SetPadding(SDL_Rect _rect) { padding = _rect; }

	static void SubscribeOnMouseHover(void(*func)(SDL_MouseMotionEvent e)) { onMouseHoverFunc = func; }
	static void SubscribeOnMouseClick(void(*func)()) { onMouseClickFunc = func; }
	static void SubscribeOnMouseDown(void(*func)(SDL_MouseButtonEvent e)) { onMouseDownFunc = func; }
	static void SubscribeOnMouseUp(void(*func)(SDL_MouseButtonEvent e)) { onMouseUpFunc = func; }

	static void SubscribeOnKeyboardDown(void(*func)(SDL_KeyboardEvent e)) { onKeyboardDownFunc = func; }
	static void SubscribeOnKeyboardUp(void(*func)(SDL_KeyboardEvent e)) { onKeyboardUpFunc = func; }
	static void SubscribeOnTextInput(void(*func)(SDL_TextInputEvent e)) { onTextInputFunc = func; }

	virtual void OnMouseHover(SDL_MouseMotionEvent e) { if (onMouseHoverFunc != NULL) { (*onMouseHoverFunc)(e); } }
	virtual void OnMouseClick() { if (onMouseClickFunc != NULL) { (*onMouseClickFunc)(); } }
	virtual void OnMouseDown(SDL_MouseButtonEvent e) { if (onMouseDownFunc != NULL) { (*onMouseDownFunc)(e); } }
	virtual void OnMouseUp(SDL_MouseButtonEvent e) { if (onMouseUpFunc != NULL) { (*onMouseUpFunc)(e); } }
	
	virtual void OnKeyboardDown(SDL_KeyboardEvent e) { if (onKeyboardDownFunc != NULL) { (*onKeyboardDownFunc)(e); } }
	virtual void OnKeyboardUp(SDL_KeyboardEvent e) { if (onKeyboardUpFunc != NULL) { (*onKeyboardUpFunc)(e); } }
	virtual void OnTextInput(SDL_TextInputEvent e) { if (onTextInputFunc != NULL) { (*onTextInputFunc)(e); } }
};
#endif


