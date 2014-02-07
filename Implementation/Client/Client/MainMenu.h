#pragma once
#include <ClientAPI.h>

class MainMenu
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 60;
		const int BUTTON_SPC_Y = 5, BUTTON_SPC_X = 5;

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
		ClientAPI::AddGuiContainer("MenuHolder", new GuiContainer());

		//-- Background
		ClientAPI::GetGuiContainer("MenuHolder")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		//-- Logo
		ClientAPI::GetGuiContainer("MenuHolder")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

		//-- Buttons
		ClientAPI::GetGuiContainer("MenuHolder")->AddGuiContainer("BtnHolder", new GuiContainer());
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

		int xBtn, yBtn, btnIndex = 0;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("CreateGameBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->AddLabel("Create Game", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->AddButton("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MenuHolder")->AddButton("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
		ClientAPI::GetGuiContainer("MenuHolder")->GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MenuHolder")->GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));

		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SubscribeOnMouseClick(MainMenu::Click_loginButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("CreateGameBtn")->SubscribeOnMouseClick(MainMenu::Click_createButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SubscribeOnMouseClick(MainMenu::Click_viewButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(MainMenu::Click_optionsButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SubscribeOnMouseClick(MainMenu::Click_tutorialButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_quitButton);
		ClientAPI::GetGuiContainer("MenuHolder")->GetButton("CreditsBtn")->SubscribeOnMouseClick(MainMenu::Click_creditsButton);
	}

	static void Click_loginButton()
	{
		cout << "Login to network.\n";
	}

	static void Click_createButton()
	{
		cout << "Create a new game.\n";
	}

	static void Click_viewButton()
	{
		cout << "View saved games.\n";
	}

	static void Click_optionsButton()
	{
		cout << "Open options menu.\n";
	}

	static void Click_tutorialButton()
	{
		cout << "View tutorial sequence.\n";
	}

	static void Click_quitButton()
	{
		ClientAPI::ExitMainLoop();
	}

	static void Click_creditsButton()
	{
		cout << "Show credits.\n";
	}
};