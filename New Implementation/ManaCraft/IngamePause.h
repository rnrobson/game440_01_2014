#pragma once
#include "ClientAPI.h"

class IngamePause
{
public:
	static bool isPaused;
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		ClientAPI::AddFont("Systema", systema);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/pauseMenuFaded.png");
		SDL_Texture *containerBackingTex = APIHelper::LoadPNGTexture("Resources/Images/pauseMenuBacking.png");
		SDL_Texture *pausedHeaderTex = APIHelper::LoadPNGTexture("Resources/GUITextures/pauseMenuHeader.png");
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");

		ClientAPI::AddTexture("PausedBackground", backgroundTex);
		ClientAPI::AddTexture("ContainerBacking", containerBackingTex);
		ClientAPI::AddTexture("PausedHeader", pausedHeaderTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);
		
		//-- Additional rects
		SDL_Rect pauseMenuRect = APIHelper::RectHelper(SCREEN_WIDTH / 2 - 200, SCREEN_HEIGHT / 2 - 150, 400, 300);

		//-- Add in menu assets
		ClientAPI::AddGuiContainer("IngamePause", new GuiContainer());

		//-- Background
		ClientAPI::GetGuiContainer("IngamePause")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("PausedBackground"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		//-- Secondary container
		ClientAPI::GetGuiContainer("IngamePause")->AddGuiContainer("PauseMenu", new GuiContainer());
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiElement("Backing", new GuiElement(ClientAPI::GetTexture("ContainerBacking"), pauseMenuRect));

		ClientAPI::GetGuiContainer("IngamePause")->Active = false;
		isPaused = false;
	}
	static void Pause()
	{
		if (!isPaused)
		{
			ClientAPI::GetGuiContainer("IngamePause")->Active = true;
			isPaused = true;
		}
		else
		{
			ClientAPI::GetGuiContainer("IngamePause")->Active = false;
			isPaused = false;
		}
	}
};