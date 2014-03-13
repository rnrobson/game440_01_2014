#include "GuiGridSquare.h"

GuiGridSquare::GuiGridSquare()
:GuiElement(APIHelper::LoadPNGTexture("Resources/Tiles/grassAndRock.png") , {0, 0, 0, 0}){
	/* TODO:
	- look through the Tiles directory and grab each tileset
	- store each tileset as its image name
	*/

	srcRect = APIHelper::RectHelper(0, 0, 32, 32);
	destRect = APIHelper::RectHelper(100, 100, 32, 32);
}

GuiGridSquare::GuiGridSquare(SDL_Texture *_texture)
:GuiElement(_texture, {0, 0, 0, 0})
{
	srcRect = APIHelper::RectHelper(0, 0, 32, 32);
	destRect = APIHelper::RectHelper(100, 100, 32, 32);
}

GuiGridSquare::GuiGridSquare(SDL_Texture *_texture, SDL_Rect _srcRect, SDL_Rect _destRect) 
:GuiElement(_texture, _destRect)
{
	srcRect = _srcRect;
	destRect = _destRect;
}

GuiGridSquare::~GuiGridSquare(void) {}

void GuiGridSquare::Draw() {
	SDL_RenderCopyEx(Window::Renderer(), texture, &srcRect, &destRect, 0.0, NULL, SDL_FLIP_NONE);
}

void GuiGridSquare::HandleMouseClickEvent() {
	if (!Active) return;
	if (!Enabled) return;

	if (Intersects({destRect.x, destRect.y, 1, 1}))
	{
		GuiElement::OnMouseClick();
	}
}
void GuiGridSquare::HandleMouseHoverEvent(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	if (Intersects({e.x, e.y, 1, 1}))
	{
		GuiElement::OnMouseHover(e);
	}
}
void GuiGridSquare::HandleMouseMotionEvent(SDL_MouseMotionEvent e){
	GuiElement::OnMouseMotion(e);
}

void GuiGridSquare::HandleMouseDownEvent(SDL_MouseButtonEvent e){
	GuiElement::OnMouseDown(e);
}
void GuiGridSquare::HandleMouseUpEvent(SDL_MouseButtonEvent e){
	GuiElement::OnMouseUp(e);
}