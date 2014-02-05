#pragma once
#include <ClientAPI.h>

class MainMenu
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 30;
		const int BUTTON_SPC_Y = 5, BUTTON_SPC_X = 5;

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		ClientAPI::AddFont("Systema", systema);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		SDL_Texture *logoTex = APIHelper::LoadPNGTexture("Resources/Images/ManaCraft.png");
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *smallBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnHover.bmp");
		SDL_Texture *smallBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnDown.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *medBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnHover.bmp");
		SDL_Texture *medBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnDown.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");
		SDL_Texture *longBtnHoverTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnHover.bmp");
		SDL_Texture *longBtnDownTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnDown.bmp");

		ClientAPI::AddTexture("GameLogo", logoTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("SmallBtnHover", smallBtnHoverTex);
		ClientAPI::AddTexture("SmallBtnDown", smallBtnDownTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("MedBtnHover", medBtnHoverTex);
		ClientAPI::AddTexture("MedBtnDown", medBtnDownTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);
		ClientAPI::AddTexture("LongBtnHover", longBtnHoverTex);
		ClientAPI::AddTexture("LongBtnDown", longBtnDownTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//-- Additional button rects
		SDL_Rect creditsBtnRect = APIHelper::RectHelper(SCREEN_WIDTH - medBtnRect.w - BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);

		//-- Add in menu assets

		//-- Logo
		ClientAPI::AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 500, MARGIN_Y, 1000, 300)));


		//-- Buttons
		ClientAPI::AddGuiContainer("BtnHolder", new GuiContainer());
		ClientAPI::GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

		int xBtn, yBtn, btnIndex = 0;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("CreateGameBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->AddLabel("Create Game", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("BtnHolder")->AddButton("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		ClientAPI::GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_onQuitButton);
		btnIndex++;

		ClientAPI::AddButton("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
		ClientAPI::GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));
	}

	static void Click_onQuitButton()
	{
		ClientAPI::ExitMainLoop();
	}
};