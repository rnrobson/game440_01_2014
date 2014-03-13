#pragma once
#include "GuiElement.h"

class GuiGridSquare : public GuiElement
{
public:
	/*unsigned int id;
	unsigned int xPos;
	unsigned int yPos;
	*/

	SDL_Rect srcRect = SDL_Rect();
	SDL_Rect destRect = SDL_Rect();
	//SDL_Texture *texture;

	GuiGridSquare();
	GuiGridSquare(SDL_Texture *_texture);
	GuiGridSquare(SDL_Texture *_texture, SDL_Rect _srcRect, SDL_Rect _destRect);
	~GuiGridSquare(void);

	virtual void Draw();

	virtual void HandleMouseClickEvent();
	virtual void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	virtual void HandleMouseHoverEvent(SDL_MouseMotionEvent e);
	virtual void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	virtual void HandleMouseUpEvent(SDL_MouseButtonEvent e);
};
