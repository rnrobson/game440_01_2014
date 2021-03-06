#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
#include "ScreenFader.h"

class ViewGamesOld
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int PADDING = 25;
		const int MARGIN = 50;
		const int LIST_SIZE_Y = 32;
		const int LIST_SPC_Y = 10, LIST_SPC_X = 30;
		const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

		TTF_Font *ogwear = APIHelper::LoadFont("Resources/Fonts/OGWEAR.ttf", 30);
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
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");

		ClientAPI::AddTexture("BackgroundPlain", backgroundTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//--Other rects
		SDL_Rect createBtnRect = APIHelper::RectHelper(SCREEN_WIDTH / 2 - longBtnRect.w / 2, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, longBtnRect.w, longBtnRect.h);
		SDL_Rect backBtnRect = APIHelper::RectHelper(BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);

		ClientAPI::AddGuiContainer("ViewGames", new GuiContainer());
		API_Util::AddSolidTexture("GameListBg", { 0, 0, 0, 70 }, SCREEN_WIDTH - PADDING * 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 3);
		API_Util::AddSolidTexture("GameBg", { 0, 0, 0, 70 }, SCREEN_WIDTH - PADDING * 4, LIST_SPC_Y + LIST_SIZE_Y);

		ClientAPI::GetGuiContainer("ViewGames")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		ClientAPI::GetGuiContainer("ViewGames")->AddGuiContainer("GamesList", new GuiContainer());
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->SetPosition(APIHelper::RectHelper(PADDING, PADDING, 0, 0));
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("GameListBg"), 
			APIHelper::RectHelper(0, 0, SCREEN_WIDTH - PADDING * 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 3)));

		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->AddGuiElement("GamesHeader",
			new Label("Game Name  |  Players  |  Game Mode  |  Game Length  |  Ongoing",
			APIHelper::RectHelper(PADDING / 2, PADDING, SCREEN_WIDTH - MARGIN, PADDING),
			ogwear, white));

		for (int i = 0; i < 5; i++)
		{
			ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->AddGuiContainer("Game" + i, new GuiContainer());
			ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->SetPosition(
				APIHelper::RectHelper(MARGIN, MARGIN * 3 + (i * ((LIST_SPC_Y * 2) + LIST_SIZE_Y)), SCREEN_WIDTH - MARGIN * 3, LIST_SIZE_Y + LIST_SPC_Y));
			ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->AddGuiElement("Game" + i,
				new Label("2v2 QM - Much robson, such maj | 3 / 4 | Sudden Death | 30m | Yes", //Get info from DB/Network
				APIHelper::RectHelper(MARGIN, 0, SCREEN_WIDTH - MARGIN * 4, LIST_SIZE_Y),
				systema, white));
			ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->AddGuiElement("Button" + i,
				new Button(ClientAPI::GetTexture("SmallBtnNormal"), APIHelper::RectHelper(0, 0, smallBtnRect.w, smallBtnRect.h)));
			ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->GetButton("Button" + i)->
				SubscribeOnMouseClick(ViewGames::Click_join);
		}

		// Refresh Game Button
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->AddGuiElement("Refresh", new Button(ClientAPI::GetTexture("LongBtnNormal"),
			APIHelper::RectHelper(centerRect.x - longBtnRect.w * 2.5, (SCREEN_HEIGHT - SCREEN_HEIGHT / 3) - (longBtnRect.h + MARGIN), longBtnRect.w, longBtnRect.h)));
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("Refresh")->AddLabel("Refresh Games", systema, black, true);
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("Refresh")->GetLabel()->SetPadding(APIHelper::RectHelper(0, 2, 0, 0));
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("Refresh")->SubscribeOnMouseClick(ViewGames::Click_refresh);

		// Create Game Button
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->AddGuiElement("CreateGameBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"),
			APIHelper::RectHelper(centerRect.x + longBtnRect.w * 1.3, (SCREEN_HEIGHT - SCREEN_HEIGHT / 3) - (longBtnRect.h + MARGIN), longBtnRect.w, longBtnRect.h)));
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->AddLabel("Create Game", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));
		ClientAPI::GetGuiContainer("ViewGames")->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->SubscribeOnMouseClick(ViewGames::Click_createGameButton);

		
		ClientAPI::GetGuiContainer("ViewGames")->AddGuiElement("InProgress", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
		ClientAPI::GetGuiContainer("ViewGames")->AddGuiElement("CheckboxLabel", new Label("Only view games in progress that I am in.",
			APIHelper::RectHelper(centerRect.x / 2, SCREEN_HEIGHT - MARGIN * 4, centerRect.x, MARGIN), systema, white));
		ClientAPI::GetGuiContainer("ViewGames")->GetCheckbox("InProgress")->SetPosition(PADDING + centerRect.x + centerRect.x / 2, (SCREEN_HEIGHT - MARGIN * 4) - 
			ClientAPI::GetGuiContainer("ViewGames")->GetCheckbox("InProgress")->GetHeight() / 4);
		ClientAPI::GetGuiContainer("ViewGames")->GetCheckbox("InProgress")->Checked = false;
		ClientAPI::GetGuiContainer("ViewGames")->GetCheckbox("InProgress")->SubscribeOnMouseClick(ViewGames::Click_checkbox);

		ClientAPI::GetGuiContainer("ViewGames")->AddGuiElement("BackBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), { backBtnRect.x, backBtnRect.y, backBtnRect.w, backBtnRect.h }));
		ClientAPI::GetGuiContainer("ViewGames")->GetButton("BackBtn")->AddLabel("Back", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("ViewGames")->GetButton("BackBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		ClientAPI::GetGuiContainer("ViewGames")->GetButton("BackBtn")->SubscribeOnMouseClick(ViewGames::Click_backButton);

		ClientAPI::GetGuiContainer("ViewGames")->Active = false;

		ClientAPI::GetGuiContainer("ViewGames")->SubscribeOnEscapeKeyPressed(ViewGames::Click_backButton);
	}

	static void Click_checkbox()
	{
		std::cout << "Fetch new values for Game List.\n";
		Click_refresh();
		//Get new values for games list
	}

	static void Click_join()
	{
		std::cout << "Join game.\n";
	}

	static void Click_refresh()
	{
		std::cout << "Refresh games.\n";
	}

	static void Click_backButton()
	{
		std::cout << "Back to main menu.\n";
		ClientAPI::GetGuiContainer("ViewGames")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		ScreenFader::FadeOut();
	}

	static void Click_createGameButton()
	{
		std::cout << "Go To Game Lobby.\n";
		ClientAPI::GetGuiContainer("ViewGames")->Active = false;
		ClientAPI::GetGuiContainer("GameLobby")->Active = true;
		ScreenFader::FadeOut();
	}
};