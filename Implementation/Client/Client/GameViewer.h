#pragma once
#include <ClientAPI.h>
#include "API_Util.h"

class GameViewer
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;

		//The main container
		ClientAPI::AddGuiContainer("GameViewer", new GuiContainer());

		//The fonts
		API_Util::AddFont("OGWEAR", "Resources/Fonts/OGWEAR.ttf", 36);
		API_Util::AddFont("Systema_11", "Resources/Fonts/9SYSTEMA.ttf", 11);
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//The colours being used
		API_Util::AddColor("White", 255, 255, 255, 255);
		API_Util::AddColor("LightBlue", 0, 162, 232, 255);
		API_Util::AddColor("Blue", 0, 135, 193, 255);
		API_Util::AddColor("Red", 255, 0, 0, 255);

		API_Util::AddTexture("Background", "Resources/Images/background.png", API_Util::PNG);
		API_Util::AddTexture("SmallBtnNormal", "Resources/GUITextures/smallBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnHover", "Resources/GUITextures/smallBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("SmallBtnDown", "Resources/GUITextures/smallBtnDown.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnNormal", "Resources/GUITextures/medBtnNormal.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnHover", "Resources/GUITextures/medBtnHover.bmp", API_Util::BMP);
		API_Util::AddTexture("MedBtnDown", "Resources/GUITextures/medBtnDown.bmp", API_Util::BMP);

		//The Background
		ClientAPI::GetGuiContainer("GameViewer")->AddGuiElement("bg", new GuiElement(ClientAPI::GetTexture("Background"), { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }));

		//The labels
		ClientAPI::GetGuiContainer("GameViewer")->AddGuiContainer("gvwCon", new GuiContainer());
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"GameName", "Game Name", { SCREEN_WIDTH - 1020, 50, 300, 25 }, "OGWEAR", "White");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"Players", "| Players", { SCREEN_WIDTH - 805, 50, 300, 25 }, "OGWEAR", "White");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"GameMode", "| Game Mode", { SCREEN_WIDTH - 645, 50, 300, 25 }, "OGWEAR", "White");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"GmaeLength", "| Game Length", { SCREEN_WIDTH - 405, 50, 300, 25 }, "OGWEAR", "White");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"Ongoing", "| Ongoing", { SCREEN_WIDTH - 155, 50, 300, 25 }, "OGWEAR", "White");

		//Position Testing for checkbox
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"Ongoin", "Checkbox Area", { (SCREEN_WIDTH / 2) - 140, SCREEN_HEIGHT - 165, 300, 100 }, "OGWEAR", "White");

		//Buttons
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"RefreshGames", { (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT - 225, 190, 45 }, "MedBtnNormal");
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"Back", { (SCREEN_WIDTH / 2) - 50, SCREEN_HEIGHT - 110, 100, 45 }, "MedBtnNormal");

		//Text for the Buttons
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"RefreshGames", "Refresh Games", "Systema_22", "Black");
		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon"),
			"Back", "Back", "Systema_22", "Black");

		//Text positions in the button
		ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon")->GetButton("RefreshGames")->
			GetLabel()->SetPadding({ 6, 8, 0, 0 });
		ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon")->GetButton("Back")->
			GetLabel()->SetPadding({ 18, 10, 0, 0 });

		//Events for the buttons
		ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon")->GetButton("Back")->
			SubscribeOnMouseClick(BackToMainMenu);
		ClientAPI::GetGuiContainer("GameViewer")->GetGuiContainer("gvwCon")->GetButton("RefreshGames")->
			SubscribeOnMouseClick(RefreshGames);

		//CheckBox
		//ClientAPI::GetGuiContainer("gvwCon")->AddCheckbox("chk", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
		//ClientAPI::GetGuiContainer("gvwCon")->GetCheckbox("chk")->Checked = true;

		ClientAPI::GetGuiContainer("GameViewer")->Active = false;
	}

	static void BackToMainMenu()
	{
		ClientAPI::GetGuiContainer("GameViewer")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		ScreenFader::FadeOut();
	}

	static void RefreshGames()
	{

	}
};