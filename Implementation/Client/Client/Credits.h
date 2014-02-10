#pragma once
#include <ClientAPI.h>

class Credits
{
public:
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

		//-- Load Textures
		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/backgroundPlain.png");
		ClientAPI::AddTexture("BackgroundPlain", backgroundTex);

		//-- Convienient rects
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//-- Add in credits assets
		ClientAPI::AddGuiContainer("Credits", new GuiContainer());

		ClientAPI::GetGuiContainer("Credits")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		/*for (int i = 0; i < 4; i++)
		{
			ClientAPI::GetGuiContainer("Credits")->AddLabel()
		}*/
	}
};
