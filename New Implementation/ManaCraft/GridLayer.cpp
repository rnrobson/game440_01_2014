#include "GridLayer.h"


//SDL_Texture *tiletexture = APIHelper::LoadPNGTexture("Resources/Tiles/grassAndRock.png");
//ClientAPI::AddTexture("TileTexture", tiletexture);


//ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("TileTest", new GridSquare(ClientAPI::GetTexture("TileTexture"), APIHelper::RectHelper(64, 0, 32, 32), APIHelper::RectHelper(10, 10, 32, 32)));


GridLayer::GridLayer(){
	SDL_Texture *tileTexture = APIHelper::LoadPNGTexture("Resources/Tiles/grassAndRock.png");
	Active = true;
	Enabled = true;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j] = GridSquare(tileTexture, APIHelper::RectHelper(64, 0, 32, 32), APIHelper::RectHelper(i * 32, j * 32, 32, 32));
		}
	}
}

GridLayer::~GridLayer(void) { }

void GridLayer::Update(double time){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].Update(time);
		}
	}
}
void GridLayer::Draw(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].Draw();
		}
	}
}

void GridLayer::HandleMouseMotionEvent(SDL_MouseMotionEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].HandleMouseMotionEvent(e);
		}
	}
}
void GridLayer::HandleMouseDownEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].HandleMouseDownEvent(e);
		}
	}
}
void GridLayer::HandleMouseUpEvent(SDL_MouseButtonEvent e)
{
	if (!Active) return;
	if (!Enabled) return;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].HandleMouseUpEvent(e);
		}
	}
}
void GridLayer::HandleMouseClickEvent()
{
	if (!Active) return;
	if (!Enabled) return;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			layer[i][j].HandleMouseClickEvent();
		}
	}
}
