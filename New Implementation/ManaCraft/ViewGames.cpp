#include "ViewGames.h"
#include "MainMenu.h"
#include "GameLobby.h"

#include "ClientAPI.h"
#include "API_Util.h"
#include "ScreenFader.h"

#include "NetworkCommands.h"

using namespace ManaCraft::Client;

ViewGames* ViewGames::instance;

ViewGames::ViewGames()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

	Load();
}

ViewGames* ViewGames::GetInstance()
{
	if (ViewGames::instance == nullptr) { ViewGames::instance = new ViewGames(); }

	return ViewGames::instance;
}

ViewGames::~ViewGames()
{
	Page::~Page();
}

void ViewGames::Load()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;
	const int PADDING = 25;
	const int MARGIN = 50;
	const int LIST_SIZE_Y = 32;
	const int LIST_SPC_Y = 10, LIST_SPC_X = 30;
	const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

	//TTF_Font *ogwear = APIHelper::LoadFont("Resources/Fonts/OGWEAR.ttf", 30);
	
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

	ClientAPI::AddGuiContainer("ViewGames", content);

	API_Util::AddSolidTexture("GameListBg", { 0, 0, 0, 70 }, SCREEN_WIDTH - PADDING * 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 3);
	API_Util::AddSolidTexture("GameBg", { 0, 0, 0, 70 }, SCREEN_WIDTH - PADDING * 4, LIST_SPC_Y + LIST_SIZE_Y);

	content->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	content->AddGuiContainer("GamesList", new GuiContainer());
	content->GetGuiContainer("GamesList")->SetPosition(APIHelper::RectHelper(PADDING, PADDING, 0, 0));
	content->GetGuiContainer("GamesList")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("GameListBg"),
		APIHelper::RectHelper(0, 0, SCREEN_WIDTH - PADDING * 2, SCREEN_HEIGHT - SCREEN_HEIGHT / 3)));

	content->GetGuiContainer("GamesList")->AddGuiElement("GamesHeader",
		new Label("Game Name  |  Players  |  Game Mode  |  Game Length  |  Ongoing",
		APIHelper::RectHelper(PADDING / 2, PADDING, SCREEN_WIDTH - MARGIN, PADDING),
		ClientAPI::GetFont("OGWEAR_30"), ClientAPI::GetColor("White")));

	for (int i = 0; i < 5; i++)
	{
		content->GetGuiContainer("GamesList")->AddGuiContainer("Game" + i, new GuiContainer());
		content->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->SetPosition(
			APIHelper::RectHelper(MARGIN, MARGIN * 3 + (i * ((LIST_SPC_Y * 2) + LIST_SIZE_Y)), SCREEN_WIDTH - MARGIN * 3, LIST_SIZE_Y + LIST_SPC_Y));
		content->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->AddGuiElement("Game" + i,
			new Label("2v2 QM - Much robson, such maj | 3 / 4 | Sudden Death | 30m | Yes", //Get info from DB/Network
			APIHelper::RectHelper(MARGIN, 0, SCREEN_WIDTH - MARGIN * 4, LIST_SIZE_Y),
			ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
		content->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->AddGuiElement("Button" + i,
			new Button(ClientAPI::GetTexture("SmallBtnNormal"), APIHelper::RectHelper(0, 0, smallBtnRect.w, smallBtnRect.h)));
		content->GetGuiContainer("GamesList")->GetGuiContainer("Game" + i)->GetButton("Button" + i)->
			SubscribeOnMouseClick(ViewGames::Click_join);
	}

	// Refresh Game Button
	content->GetGuiContainer("GamesList")->AddGuiElement("Refresh", new Button(ClientAPI::GetTexture("LongBtnNormal"),
		APIHelper::RectHelper(centerRect.x - longBtnRect.w * 2.5, (SCREEN_HEIGHT - SCREEN_HEIGHT / 3) - (longBtnRect.h + MARGIN), longBtnRect.w, longBtnRect.h)));
	content->GetGuiContainer("GamesList")->GetButton("Refresh")->AddLabel("Refresh Games", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("GamesList")->GetButton("Refresh")->GetLabel()->SetPadding(APIHelper::RectHelper(0, 2, 0, 0));
	content->GetGuiContainer("GamesList")->GetButton("Refresh")->SubscribeOnMouseClick(ViewGames::Click_refresh);

	// Create Game Button
	content->GetGuiContainer("GamesList")->AddGuiElement("CreateGameBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"),
		APIHelper::RectHelper(centerRect.x + longBtnRect.w * 1.3, (SCREEN_HEIGHT - SCREEN_HEIGHT / 3) - (longBtnRect.h + MARGIN), longBtnRect.w, longBtnRect.h)));
	content->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->AddLabel("Create Game", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));
	content->GetGuiContainer("GamesList")->GetButton("CreateGameBtn")->SubscribeOnMouseClick(ViewGames::Click_createGameButton);

	content->AddGuiElement("InProgress", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
	content->AddGuiElement("CheckboxLabel", new Label("Only view games in progress that I am in.",
		APIHelper::RectHelper(centerRect.x / 2, SCREEN_HEIGHT - MARGIN * 4, centerRect.x, MARGIN), ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	content->GetCheckbox("InProgress")->SetPosition(PADDING + centerRect.x + centerRect.x / 2, (SCREEN_HEIGHT - MARGIN * 4) -
		content->GetCheckbox("InProgress")->GetHeight() / 4);
	content->GetCheckbox("InProgress")->Checked = false;
	content->GetCheckbox("InProgress")->SubscribeOnMouseClick(ViewGames::Click_checkbox);

	content->AddGuiElement("BackBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), { backBtnRect.x, backBtnRect.y, backBtnRect.w, backBtnRect.h }));
	content->GetButton("BackBtn")->AddLabel("Back", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	content->GetButton("BackBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	content->GetButton("BackBtn")->SubscribeOnMouseClick(ViewGames::Click_backButton);

	content->SetSfx1Audio(ClientAPI::GetAudio("BtnAudio"));

	//content->Active = false;

	content->SubscribeOnEscapeKeyPressed(ViewGames::Click_backButton);
}

void ViewGames::Update(double time)
{
	Page::Update(time);
}

void ViewGames::Draw()
{
	Page::Draw();
}

//===================
//----------- Events
//===================

void ViewGames::OnEnterPressed()
{

}

void ViewGames::OnEscapePressed()
{

}

void ViewGames::Click_checkbox()
{
	std::cout << "Fetch new values for Game List.\n";
	ViewGames::GetInstance()->GetContent()->Sfx1Play();
	Click_refresh();
	//Get new values for games list
}

void ViewGames::Click_join()
{
	ViewGames::GetInstance()->GetContent()->Sfx1Play();

	ManaCraft::Client::NetworkCommands::JoinGame(1);//gameId set to 1 for now
}

void ViewGames::Click_refresh()
{
	ViewGames::GetInstance()->GetContent()->Sfx1Play();

	ManaCraft::Client::NetworkCommands::RefreshGames();
}

void ViewGames::Click_backButton()
{
	std::cout << "Back to main menu.\n";
	ViewGames::GetInstance()->GetContent()->Sfx1Play();

	//content->Active = false;
	//ClientAPI::GetGuiContainer("MainMenu")->Active = true;

	ClientAPI::SetFocus(MainMenu::GetInstance());
	ScreenFader::GetInstance()->FadeOut();
}

void ViewGames::Click_createGameButton()
{
	std::cout << "CreateGame";
	ViewGames::GetInstance()->GetContent()->Sfx1Play();

	//content->Active = false;
	//ClientAPI::GetGuiContainer("GameLobby")->Active = true;
	ClientAPI::SetFocus(GameLobby::GetInstance());

	ScreenFader::GetInstance()->FadeOut();

	ManaCraft::Client::NetworkCommands::CreateGame();
}