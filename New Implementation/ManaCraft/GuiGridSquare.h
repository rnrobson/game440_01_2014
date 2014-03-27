#pragma once
#include "GuiElement.h"
#include "GridSquare.h"

class GuiGridSquare : public GuiElement
{
public:
	SDL_Rect m_sourceRectangle = SDL_Rect();
	SDL_Rect m_destinationRectangle = SDL_Rect();
	SDL_Texture* m_gridTexture;

	GuiGridSquare();
	GuiGridSquare(SDL_Texture* _tileSet, GridSquare _gridSquare, unsigned int width, unsigned int height);
	~GuiGridSquare(void);

	virtual void Draw();

	virtual void HandleMouseClickEvent();
	virtual void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	virtual void HandleMouseHoverEvent(SDL_MouseMotionEvent e);
	virtual void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	virtual void HandleMouseUpEvent(SDL_MouseButtonEvent e);
};
