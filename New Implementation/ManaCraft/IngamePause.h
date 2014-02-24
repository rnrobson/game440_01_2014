#pragma once
#include "ClientAPI.h"

class IngamePause
{
private:
	static bool isPaused;
public:
	static void Load()
	{
		const int SCREEN_WIDTH = Window::Box().w;
		const int SCREEN_HEIGHT = Window::Box().h;
		const int MARGIN_Y = 20;
		const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

		TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

		ClientAPI::AddFont("Systema", systema);

		//-- Main colors
		SDL_Color black = APIHelper::ColourHelper(0, 0, 0, 255);
		SDL_Color white = APIHelper::ColourHelper(255, 255, 255, 255);

		ClientAPI::AddColour("Black", black);
		ClientAPI::AddColour("White", white);

		SDL_Texture *backgroundTex = APIHelper::LoadPNGTexture("Resources/Images/pauseMenuFaded.png");
		SDL_Texture *containerBackingTex = APIHelper::LoadPNGTexture("Resources/Images/pauseMenuBacking.png");
		SDL_Texture *pausedHeaderTex = APIHelper::LoadPNGTexture("Resources/GUITextures/pauseMenuHeader.png");
		SDL_Texture *smallBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/smallBtnNormal.bmp");
		SDL_Texture *medBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/medBtnNormal.bmp");
		SDL_Texture *longBtnNormalTex = APIHelper::LoadBMPImage("Resources/GUITextures/longBtnNormal.bmp");

		ClientAPI::AddTexture("PausedBackground", backgroundTex);
		ClientAPI::AddTexture("ContainerBacking", containerBackingTex);
		ClientAPI::AddTexture("PausedHeader", pausedHeaderTex);
		ClientAPI::AddTexture("SmallBtnNormal", smallBtnNormalTex);
		ClientAPI::AddTexture("MedBtnNormal", medBtnNormalTex);
		ClientAPI::AddTexture("LongBtnNormal", longBtnNormalTex);

		//-- Convienient rects
		SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
		SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
		SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
		SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);
		
		//-- Additional rects
		SDL_Rect pauseMenuRect = APIHelper::RectHelper(0, 0, 400, 300);

		//-- Add in menu assets
		ClientAPI::AddGuiContainer("IngamePause", new GuiContainer());

		//-- Background
		ClientAPI::GetGuiContainer("IngamePause")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("PausedBackground"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

		//-- Secondary container
		ClientAPI::GetGuiContainer("IngamePause")->AddGuiContainer("PauseMenu", new GuiContainer());
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiElement("Backing", new GuiElement(ClientAPI::GetTexture("ContainerBacking"), pauseMenuRect));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->SetPosition(APIHelper::RectHelper(centerRect.x - 200, centerRect.y - 150, 400, 300));

		//-- Header
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiElement("Header",
			new GuiElement(ClientAPI::GetTexture("PausedHeader"), APIHelper::RectHelper(pauseMenuRect.x + pauseMenuRect.w / 2 - 62, pauseMenuRect.y + MARGIN_Y, 125, 40)));

		//-- Buttons
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->AddGuiContainer("BtnHolder", new GuiContainer());
		SDL_Rect containerPos = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetPosition();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(containerPos.x + (pauseMenuRect.w / 2 - longBtnRect.w / 2), containerPos.y + 65, 0, 0));

		int xBtn, btnIndex = 0;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddButton("ResumeBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->GetX();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->AddLabel("Resume", systema, black, true);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddButton("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", systema, black, true);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddButton("SaveQuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->GetX();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->AddLabel("Save & Quit", systema, black, true);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddButton("QuitMenuBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->GetX();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->AddLabel("Quit > Menu", systema, black, true);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->AddButton("QuitDesktopBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
		xBtn = ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->GetX();
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->AddLabel("Quit > Desktop", systema, black, true);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
		btnIndex++;

		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->SubscribeOnMouseClick(IngamePause::Click_resume);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(IngamePause::Click_options);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->SubscribeOnMouseClick(IngamePause::Click_save);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->SubscribeOnMouseClick(IngamePause::Click_quitMenu);
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitDesktopBtn")->SubscribeOnMouseClick(IngamePause::Click_quitDesktop);

		ClientAPI::GetGuiContainer("IngamePause")->Active = false;
		isPaused = false;
	}

	static void Pause()
	{
		if (!isPaused)
		{
			ClientAPI::GetGuiContainer("IngamePause")->Active = true;
			isPaused = true;
			//ScreenFader::FadeOut();
		}
		else
		{
			ClientAPI::GetGuiContainer("IngamePause")->Active = false;
			isPaused = false;
			//ScreenFader::FadeOut();
		}
	}

	static void Pause(std::string containerID)
	{
		releaseAllButtons(); //BANDAID
		if (!isPaused)
		{
			ClientAPI::GetGuiContainer(containerID)->Active = false;
			ClientAPI::GetGuiContainer("IngamePause")->Active = true;
			isPaused = true;
			//ScreenFader::FadeOut();
		}
		else
		{
			isPaused = false;
			ClientAPI::GetGuiContainer(containerID)->Active = true;
			ClientAPI::GetGuiContainer("IngamePause")->Active = false;
			//ScreenFader::FadeOut();
		}
	}

	static void Click_resume()
	{
		Pause();
	}

	static void Click_options()
	{
		std::cout << "Go to Options\n";
		Pause();
		ClientAPI::GetGuiContainer("Options")->Active = true;
	}

	static void Click_save()
	{
		std::cout << "Save game\n";
		Pause();
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		//ScreenFader::FadeOut();
	}

	static void Click_quitMenu()
	{
		Pause();
		ClientAPI::SetAllGuiContainersInactive(); //Disables all the current GUI Objects before setting the main menu to active
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		//ScreenFader::FadeOut();
	}

	static void Click_quitDesktop()
	{
		ClientAPI::ExitMainLoop();
	}

	//BANDAID FIX FOR THE BUTTON DARKENING PROBLEM
	static void releaseAllButtons(){
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("ResumeBtn")->isPressedDown = false;
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->isPressedDown = false;
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("SaveQuitBtn")->isPressedDown = false;
		ClientAPI::GetGuiContainer("IngamePause")->GetGuiContainer("PauseMenu")->GetGuiContainer("BtnHolder")->GetButton("QuitMenuBtn")->isPressedDown = false;
	}
};