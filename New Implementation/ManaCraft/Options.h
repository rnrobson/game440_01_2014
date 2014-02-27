#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
//#include <SDL_mixer.h>

class Options
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 40;

		//add main container
		ClientAPI::AddGuiContainer("Options", new GuiContainer());

		//add font
		API_Util::AddFont("OGWEAR", "Resources/Fonts/OGWEAR.ttf", 36);
		API_Util::AddFont("Systema_11", "Resources/Fonts/9SYSTEMA.ttf", 11);
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//add colors to be used for buttons, labels, etc
		API_Util::AddColor("White", 255, 255, 255, 255);
		API_Util::AddColor("LightBlue", 0, 162, 232, 255);
		API_Util::AddColor("Red", 255, 0, 0, 255);

		//add textures
		API_Util::AddTexture("GameLogo", "Resources/Images/ManaCraft.png", API_Util::PNG);
		API_Util::AddTexture("Background", "Resources/Images/background.png", API_Util::PNG);
		API_Util::AddTexture("SmallBtnNormal", "Resources/GUITextures/smallBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnHover", "Resources/GUITextures/smallBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnDown", "Resources/GUITextures/smallBtnDown.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnHover", "Resources/GUITextures/medBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnDown", "Resources/GUITextures/medBtnDown.bmp", API_Util::BMP);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//add background
		ClientAPI::GetGuiContainer("Options")->AddGuiElement("background", new GuiElement(ClientAPI::GetTexture("Background"), { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }));

		//add logo
		ClientAPI::GetGuiContainer("Options")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

		//add labels
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("Options"), "Lbl_Options", "Options", { 450, 400, 200, 100 }, "OGWEAR", "White");

		//add button
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("Options"), "returnToMainMenu", { 900, 720, 100, 30 }, "MedBtnNormal");

		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("Options"),
			"returnToMainMenu", "Back", "Systema_11", "Black");

		ClientAPI::GetGuiContainer("Options")->GetButton("returnToMainMenu")->GetLabel()->SetPadding({ 29, 8, 0, 0 });

		ClientAPI::GetGuiContainer("Options")->GetButton("returnToMainMenu")->SubscribeOnMouseClick(ReturnToMainMenu);

		//Making options container not visible
		ClientAPI::GetGuiContainer("Options")->Active = false;
	}

	static void ReturnToMainMenu() {
		ClientAPI::GetGuiContainer("Options")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		ScreenFader::FadeOut();
	}
};
