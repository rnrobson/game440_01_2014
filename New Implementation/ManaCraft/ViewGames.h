#pragma once
#include "ClientAPI.h"
#include "API_Util.h"

class ViewGames
{
public:
	static void Load()
	{
		//ClientAPI::GetGuiContainer("cnt")->AddCheckbox("chk", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
		//ClientAPI::GetGuiContainer("cnt")->GetCheckbox("chk")->Checked = true;

		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int LABEL_SPACE_Y = 25;
		const int LIST_SPC_Y = 15, LIST_SPC_X = 30;

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);
		TTF_Font *systemaLarge = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 30);

		ClientAPI::AddFont("Systema", systema);
		ClientAPI::AddFont("SystemaL", systemaLarge);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		//--Load textures
		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/backgroundPlain.png");

		ClientAPI::AddTexture("BackgroundPlain", backgroundTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		ClientAPI::AddGuiContainer("ViewGames", new GuiContainer());
		API_Util::AddSolidTexture("GameListBg", { 0, 0, 0, 70 }, SCREEN_WIDTH - 100, SCREEN_HEIGHT - SCREEN_HEIGHT / 4);

		ClientAPI::GetGuiContainer("ViewGames")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		for (int i = 0; i < 10; i++)
		{

		}

		ClientAPI::GetGuiContainer("ViewGames")->Active = false;
	}
};