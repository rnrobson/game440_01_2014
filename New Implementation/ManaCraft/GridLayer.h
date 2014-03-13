#pragma once
#include "GridSquare.h"

class GridLayer {
public:
	char tileSize;
	unsigned int rows;
	unsigned int columns;

	bool Active;
	bool Enabled;

	GridSquare layer[10][10];

	GridLayer();
	~GridLayer(void);

	void Update(double time);
	void Draw();

	void HandleMouseClickEvent();
	void HandleMouseMotionEvent(SDL_MouseMotionEvent e);
	void HandleMouseDownEvent(SDL_MouseButtonEvent e);
	void HandleMouseUpEvent(SDL_MouseButtonEvent e);

	void SetPosition(SDL_Rect){

	}
};

