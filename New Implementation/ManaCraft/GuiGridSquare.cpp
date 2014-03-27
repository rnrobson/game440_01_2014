#include "GuiGridSquare.h"

GuiGridSquare::GuiGridSquare()
:GuiElement(APIHelper::LoadPNGTexture("Resources/Tiles/grassAndRock.png") , {0, 0, 0, 0}){
	/* TODO:
	- look through the Tiles directory and grab each tileset
	- store each tileset as its image name
	*/
	m_sourceRectangle = APIHelper::RectHelper(0, 0, 32, 32);
	m_destinationRectangle = APIHelper::RectHelper(100, 100, 32, 32);
}

GuiGridSquare::GuiGridSquare(SDL_Texture* _tileSet, GridSquare _gridSquare, unsigned int _width, unsigned int _height){
	int _widthInTiles, _heightInTiles;
	int x = 0;
	int y = 0;

	m_gridTexture = _tileSet;
	SDL_QueryTexture(m_gridTexture, NULL, NULL, &_widthInTiles, &_heightInTiles); //Query the texture to return the width and height
	_widthInTiles /= _width;  //Divide the full width by the tile width to get the width in tiles
	_heightInTiles /= _height; //Do the same with the height

	for (int i = 0; i < _heightInTiles * _widthInTiles; i++){
		if (i == _gridSquare.id){
			break;
		}else{
			x++;
			if (x != 0 && x % _widthInTiles == 0){x = 0; y++;	}
		}
	}

	m_sourceRectangle = APIHelper::RectHelper(x * _width, y * _height, _width, _height);
	m_destinationRectangle = APIHelper::RectHelper(_gridSquare.xPos * _width, 
																				   _gridSquare.yPos * _height,
																				   _width, _height);

}

GuiGridSquare::~GuiGridSquare(void) {}

void GuiGridSquare::Draw() {
	SDL_RenderCopyEx(Window::Renderer(), m_gridTexture, &m_sourceRectangle, &m_destinationRectangle, 0.0, NULL, SDL_FLIP_NONE);
}

void GuiGridSquare::HandleMouseClickEvent() {
	if (!Active) return;
	if (!Enabled) return;

	if (Intersects({ m_destinationRectangle.x, m_destinationRectangle.y, 1, 1 }))
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