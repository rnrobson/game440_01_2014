#pragma once
#ifndef API_HELPER_H
#define API_HELPER_H

#include "Includes.h"
#include "Window.h"

class APIHelper
{
public:
	static SDL_Texture* LoadBMPImage(const std::string &file) { return Window::LoadImage(file); }
	static SDL_Texture* LoadPNGTexture(const std::string &file) { return Window::LoadTexture(file); }
	static TTF_Font* LoadFont(const std::string &file, int fontSize) { return Window::LoadFont(file, fontSize); }

	static SDL_Rect RectHelper(int x, int y, int w, int h) { return { x, y, w, h }; } // Window::RectHelper(x, y, w, h); }
	static SDL_Color ColourHelper(int r, int g, int b, int a) { return { r, g, b, a }; }
};

#endif