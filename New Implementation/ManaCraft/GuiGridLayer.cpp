#include "GuiGridLayer.h"


//SDL_Texture *tiletexture = APIHelper::LoadPNGTexture("Resources/Tiles/grassAndRock.png");
//ClientAPI::AddTexture("TileTexture", tiletexture);


//ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("TileTest", new GridSquare(ClientAPI::GetTexture("TileTexture"), APIHelper::RectHelper(64, 0, 32, 32), APIHelper::RectHelper(10, 10, 32, 32)));


GuiGridLayer::GuiGridLayer() {}
GuiGridLayer::GuiGridLayer(SDL_Texture* _tileTexture, unsigned int _rows, unsigned int _columns){
	Active = true;
	Enabled = true;
	rows = _rows;
	columns = _columns;

	layer = std::vector<GuiGridSquare*>();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			GridSquare newGridSquare;
			newGridSquare.xPos = i;
			newGridSquare.yPos = j;
			newGridSquare.id = 15;
			layer.push_back(new GuiGridSquare(_tileTexture, newGridSquare, 32, 32));
		}
	}
}

GuiGridLayer::~GuiGridLayer(void) { }

void GuiGridLayer::Update(double time){
	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->Update(time);
	}
}
void GuiGridLayer::Draw(){
	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->Draw();
	}
}

void GuiGridLayer::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->HandleMouseMotionEvent(e);
	}
}
void GuiGridLayer::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->HandleMouseDownEvent(e);
	}
}
void GuiGridLayer::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->HandleMouseUpEvent(e);
	}
}
void GuiGridLayer::HandleMouseClickEvent()
{
	if (!Active) return;
	if (!Enabled) return;

	for (size_t i = 0; i < layer.size(); i++){
		layer.at(i)->HandleMouseClickEvent();
	}
}
