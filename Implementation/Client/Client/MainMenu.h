#pragma once
#include <ClientAPI.h>

class MainMenu
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 40;
		const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;
		bool isLoggedIn = false;

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		ClientAPI::AddFont("Systema", systema);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/background.png");
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

		ClientAPI::AddTexture("Background", backgroundTex);
		ClientAPI::AddTexture("GameLogo", logoTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

		//-- Additional button rects
		SDL_Rect creditsBtnRect = APIHelper::RectHelper(SCREEN_WIDTH - medBtnRect.w - BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);

		//-- Add in menu assets
		ClientAPI::AddGuiContainer("MainMenu", new GuiContainer());

		//-- Background
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		//-- Logo
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

		//-- Buttons
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiContainer("BtnHolder", new GuiContainer());
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

		int xBtn, btnIndex = 0;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("CreateGameBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->AddLabel("Create Game", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddButton("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->AddButton("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SubscribeOnMouseClick(MainMenu::Click_loginButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->SubscribeOnMouseClick(MainMenu::Click_createButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SubscribeOnMouseClick(MainMenu::Click_viewButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(MainMenu::Click_optionsButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SubscribeOnMouseClick(MainMenu::Click_tutorialButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_quitButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->SubscribeOnMouseClick(MainMenu::Click_creditsButton);
	}

	static void Click_loginButton()
	{
		std::cout << "Login to network.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Enabled = false;
		ClientAPI::GetGuiContainer("LoginPopup")->Active = true;
	}

	static void Click_logoutButton()
	{
		std::cout << "Logout out of network.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Enabled = false;
		ClientAPI::GetGuiContainer("LogoutPopUp")->Active = true;
	}

	static void Click_createButton()
	{
		std::cout << "Create a new game.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("GameLobby")->Active = true;
		ScreenFader::FadeOut();
	}

	static void Click_viewButton()
	{
		std::cout << "View saved games.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("GameViewer")->Active = true;
		ScreenFader::FadeOut();
	}

	static void Click_optionsButton()
	{
		std::cout << "Open options menu.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("Options")->Active = true;
		ScreenFader::FadeOut();
	}

	static void Click_tutorialButton()
	{
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("GUI")->Active = true;
		ScreenFader::FadeOut();
	}

	static void Click_quitButton()
	{
		ClientAPI::ExitMainLoop();
	}

	static void Click_creditsButton()
	{
		std::cout << "Show credits.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("Credits")->Active = true;
		ScreenFader::FadeOut();
	}
};