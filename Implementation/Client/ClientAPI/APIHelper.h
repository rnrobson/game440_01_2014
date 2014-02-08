#pragma once
#ifndef API_HELPER_H
#define API_HELPER_H

#include "Includes.h"
#include "APIEvents.h"
#include "Window.h"

class APIHelper
{
public:

	static SDL_Texture* SolidColourTexture(int width, int height, SDL_Color colour)
	{
		SDL_Surface *surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0, 0, 0, 1); // 16
		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, colour.r, colour.g, colour.b));

		SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::Renderer(), surface);
		SDL_SetTextureAlphaMod(texture, colour.a);
		return texture;
	}

	static SDL_Texture* LoadBMPImage(const std::string &file) { return Window::LoadImage(file); }
	static SDL_Texture* LoadPNGTexture(const std::string &file) { return Window::LoadTexture(file); }
	static TTF_Font* LoadFont(const std::string &file, int fontSize) { return Window::LoadFont(file, fontSize); }

	static SDL_Rect RectHelper(int x, int y, int w, int h) { return { x, y, w, h }; } // Window::RectHelper(x, y, w, h); }
	static SDL_Color ColourHelper(int r, int g, int b, int a) { return { r, g, b, a }; }

	static bool DidKeyGetPressed(SDL_Scancode key) { return APIEvents::DidKeyGetPressed(key); }
	static bool DidMouseClick() { return APIEvents::DidMouseClick(); }
};

#endif