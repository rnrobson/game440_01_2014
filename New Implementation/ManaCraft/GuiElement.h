#pragma once
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H

//#include "ClientAPI.h"
//#include "Includes.h"
//#include <SDL.h>
#include "Window.h"
#include "APIHelper.h"

class GuiElement
{
protected:
	SDL_Texture *texture;
	SDL_Rect rect;
	SDL_Rect offset;
	SDL_Rect padding;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

	void(*onMouseClickFunc)();
	void(*onMouseMotionFunc)(SDL_MouseMotionEvent e);
	void(*onMouseHoverFunc)(SDL_MouseMotionEvent e);
	void(*onMouseDownFunc)(SDL_MouseButtonEvent e);
	void(*onMouseUpFunc)(SDL_MouseButtonEvent e);

	void(*onEscapeKeyPressed)();
	void(*onEnterKeyPressed)();
	void(*onKeyboardDownFunc)(SDL_KeyboardEvent e);
	void(*onKeyboardUpFunc)(SDL_KeyboardEvent e);
	void(*onTextInputFunc)(SDL_TextInputEvent e);

	void SetupHelper()
	{
		onMouseClickFunc = nullptr;
		onMouseMotionFunc = nullptr;
		onMouseHoverFunc = nullptr;
		onMouseDownFunc = nullptr;
		onMouseUpFunc = nullptr;

		onEscapeKeyPressed = nullptr;
		onEnterKeyPressed = nullptr;
		onKeyboardDownFunc = nullptr;
		onKeyboardUpFunc = nullptr;
		onTextInputFunc = nullptr;

		offset = { 0, 0, 0, 0 };
		padding = { 0, 0, 0, 0 };
	}
public:
	bool Active = true;
	bool Enabled = true;

	GuiElement()
	{
		texture = nullptr;
		rect = { 0, 0, 0, 0 };
		SetupHelper();
	}
	GuiElement(SDL_Texture *_texture, SDL_Rect _rect)
	{
		texture = _texture;
		rect = _rect;
		SetupHelper();
	}
	virtual ~GuiElement() { Free(); }
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

	virtual void Update(double _time) { if (Active) { if (Enabled) {} } }
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

	float Layer = 0.0f;
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

	void SubscribeOnMouseClick(void(*func)()) { onMouseClickFunc = func; }
	void SubscribeOnMouseMove(void(*func)(SDL_MouseMotionEvent e)) { onMouseMotionFunc = func; }
	void SubscribeOnMouseHover(void(*func)(SDL_MouseMotionEvent e)) { onMouseHoverFunc = func; }
	void SubscribeOnMouseDown(void(*func)(SDL_MouseButtonEvent e)) { onMouseDownFunc = func; }
	void SubscribeOnMouseUp(void(*func)(SDL_MouseButtonEvent e)) { onMouseUpFunc = func; }

	void SubscribeOnEscapeKeyPressed(void(*func)()) { onEscapeKeyPressed = func; }
	void SubscribeOnEnterKeyPressed(void(*func)()) { onEnterKeyPressed = func; }
	void SubscribeOnKeyboardDown(void(*func)(SDL_KeyboardEvent e)) { onKeyboardDownFunc = func; }
	void SubscribeOnKeyboardUp(void(*func)(SDL_KeyboardEvent e)) { onKeyboardUpFunc = func; }
	void SubscribeOnTextInput(void(*func)(SDL_TextInputEvent e)) { onTextInputFunc = func; }

	virtual void OnMouseClick() {
		if (Enabled && Active) {
			if (onMouseClickFunc != NULL) {
				(*onMouseClickFunc)(); 
			} 
		} 
	}
	virtual void OnMouseMotion(SDL_MouseMotionEvent e) { 
		if (Enabled && Active) {
			if (onMouseMotionFunc != NULL) {
				(*onMouseMotionFunc)(e); 
			} 
		} 
	}
	virtual void OnMouseHover(SDL_MouseMotionEvent e) {
		if (Enabled && Active) {
			if (onMouseHoverFunc != NULL) {
				(*onMouseHoverFunc)(e); 
			}
		}
	}
	virtual void OnMouseDown(SDL_MouseButtonEvent e) {
		if (Enabled && Active) {
			if (onMouseDownFunc != NULL) {
				(*onMouseDownFunc)(e); 
			}
		}
	}
	virtual void OnMouseUp(SDL_MouseButtonEvent e) {
		if (Enabled && Active) {
			if (onMouseUpFunc != NULL) {
				(*onMouseUpFunc)(e); 
			}
		}
	}
	
	virtual void OnEscapeKeyPressed() {
		if (Enabled && Active) {
			if (onEscapeKeyPressed != NULL) {
				(*onEscapeKeyPressed)(); 
			}
		}
	}
	virtual void OnEnterKeyPressed() {
		if (Enabled && Active) {
			if (onEnterKeyPressed != NULL) {
				(*onEnterKeyPressed)();
			}
		}
	}
	virtual void OnKeyboardDown(SDL_KeyboardEvent e) {
		if (Enabled && Active) {
			if (onKeyboardDownFunc != NULL) {
				(*onKeyboardDownFunc)(e);
			}
		}
	}
	virtual void OnKeyboardUp(SDL_KeyboardEvent e) {
		if (Enabled && Active) {
			if (onKeyboardUpFunc != NULL) {
				(*onKeyboardUpFunc)(e); 
			}
		}
	}
	virtual void OnTextInput(SDL_TextInputEvent e) {
		if (Enabled && Active) {
			if (onTextInputFunc != NULL) {
				(*onTextInputFunc)(e); 
			}
		}
	}
};
#endif


