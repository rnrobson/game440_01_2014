#pragma once
#ifndef WINDOW_H
#define WINDOW_H

//#include "ClientAPI.h"
#include "Includes.h"
#include <memory>

//What we think our window class should look like
class Window {
public:
	//Start SDL and TTF, create the window and renderer
	static void Init(std::string title = "Window", int width = 1024, int height = 768);
	//Quit SDL and TTF
	static void Quit();

	// Change Window Title
	static void Title(std::string title);

	//Draw an SDL_Texture
	static void Draw(SDL_Texture *tex, int x, int y, int w = 0, int h = 0);
	static void Draw(SDL_Texture*, ...);
	//Load an image
	static SDL_Texture* LoadImage(const std::string &file);
	static SDL_Texture* LoadTexture(const std::string &file);
	// Load a Font
	static TTF_Font* LoadFont(const std::string &file, int fontSize);


	//Render some text
	static SDL_Texture* RenderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize);
	//Clear window
	static void Clear();
	//Present renderer
	static void Present();
	//Get the window's box
	static SDL_Rect Box();
	static SDL_Rect RectHelper(int x, int y, int w, int h)
	{
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		return rect;
	}

	/**
	*  Draw a SDL_Texture to the screen at dstRect with various other options
	*  @param tex The SDL_Texture to draw
	*  @param dstRect The destination position and width/height to draw the texture with
	*  @param clip The clip to apply to the image, if desired
	*  @param angle The rotation angle to apply to the texture, default is 0
	*  @param xPivot The x coordinate of the pivot, relative to (0, 0) being center of dstRect
	*  @param yPivot The y coordinate of the pivot, relative to (0, 0) being center of dstRect
	*  @param flip The flip to apply to the image, default is none
	*/
	static void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL,
		float angle = 0.0, int xPivot = 0, int yPivot = 0,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	static SDL_Renderer* Renderer();

private:
	static std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> mWindow;
	static std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> mRenderer;
	static SDL_Rect mBox;
};
#endif
