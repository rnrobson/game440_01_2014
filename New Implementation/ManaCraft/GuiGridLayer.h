#pragma once
#include "GuiGridSquare.h"

class GuiGridLayer {
public:
	char tileSize;
	unsigned int rows;
	unsigned int columns;

	bool Active;
	bool Enabled;

	GuiGridSquare layer[10][10];

	GuiGridLayer();
	~GuiGridLayer(void);

	void Update(double time);
	void Draw();

	void HandleMouseClickEvent();
	void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	void HandleMouseUpEvent(SDL_MouseButtonEvent e);

	void SetPosition(SDL_Rect){

	}
};

