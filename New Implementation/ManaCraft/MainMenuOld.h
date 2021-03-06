#pragma once
#include "ClientAPI.h"
#include "ParticleSystem.h"
#include "AnimatedSprite.h"
#include "MainMenu.h"

class MainMenuOld
{
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 40;
		const int BUTTON_SPC_Y = 20, BUTTON_SPC_X = 10;

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
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");

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

		// THIS CAUSES PROBLEMS:
		//ClientAPI::GetGuiContainer("MainMenu")->AddGridLayer("Grid", new GridLayer());

		//-- Background
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		//-- Logo
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

		//-- Buttons
		ClientAPI::GetGuiContainer("MainMenu")->AddGuiContainer("BtnHolder", new GuiContainer());
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

		int xBtn, btnIndex = 0;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->AddGuiElement("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("MainMenu")->AddGuiElement("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));

		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SubscribeOnMouseClick(MainMenu::Click_loginButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SubscribeOnMouseClick(MainMenu::Click_viewButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(MainMenu::Click_optionsButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SubscribeOnMouseClick(MainMenu::Click_tutorialButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_quitButton);
		ClientAPI::GetGuiContainer("MainMenu")->GetButton("CreditsBtn")->SubscribeOnMouseClick(MainMenu::Click_creditsButton);

		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		//FOR TESTING ANIMATED SPRITE
		//SDL_Texture *texture = nullptr;
		//texture = IMG_LoadTexture(Window::Renderer(), "Resources/Sprites/MinionSS.png");
		//if (texture == nullptr)//in case creating renderer fails
		//{
		//	std::cout << SDL_GetError() << std::endl;

		//}
		//AnimatedSprite *sp = new AnimatedSprite(texture, 100, 100,4,4);
		//
		//int i = 0;
		//sp->Down();
		//while (i < 5000)
		//{
		//	sp->Update();
		//}

	}

	static void Click_loginButton()
	{
		std::cout << "Login to network.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Enabled = false;
		ClientAPI::GetGuiContainer("LoginPopup")->Active = true;
	}

	static void Click_viewButton()
	{
		std::cout << "View saved games.\n";
		ClientAPI::GetGuiContainer("MainMenu")->Active = false;
		ClientAPI::GetGuiContainer("ViewGames")->Active = true;
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
		ClientAPI::GetGuiContainer("InGameGUI")->Active = true;
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