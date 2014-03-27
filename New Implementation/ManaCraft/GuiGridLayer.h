#pragma once
#include "GuiGridSquare.h"

class GuiGridLayer : public GuiElement {
public:
	char tileSize;
	unsigned int rows;
	unsigned int columns;

	bool Active;
	bool Enabled;
	std::vector<GuiGridSquare*> layer;

	GuiGridLayer();
	GuiGridLayer(SDL_Texture* _tileTexture, unsigned int _rows, unsigned int _columns);
	~GuiGridLayer(void);

	virtual void Update(double time);
	virtual void Draw();

	void HandleMouseClickEvent();
	void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	void HandleMouseUpEvent(SDL_MouseButtonEvent e);

	void SetPosition(SDL_Rect){

	}
};

