#pragma once
#include "ClientAPI.h"
#include "API_Util.h"
#include "SDL_mixer.h"

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
		ClientAPI::GetGuiContainer("Options")->AddGuiContainer("OptionsForeground", new GuiContainer());

		//add font
		ClientAPI::AddAudio("OptionsAudio", APIHelper::LoadAudioFile("Resources/Audios/Menu/Bg.ogg"));
		API_Util::AddFont("OGWEAR", "Resources/Fonts/OGWEAR.ttf", 36);
		API_Util::AddFont("Systema_11", "Resources/Fonts/9SYSTEMA.ttf", 11);
		API_Util::AddFont("Systema_22", "Resources/Fonts/9SYSTEMA.ttf", 22);

		//add colors to be used for buttons, labels, etc
		API_Util::AddColor("White", 255, 255, 255, 255);
		API_Util::AddColor("LightBlue", 0, 162, 232, 255);
		API_Util::AddColor("Red", 255, 0, 0, 255);

		ClientAPI::GetGuiContainer("Options")->SetBackgroundAudio(ClientAPI::GetAudio("OptionsAudio"));
		ClientAPI::GetGuiContainer("Options")->Play();

		//add textures
		API_Util::AddTexture("GameLogo", "Resources/Images/ManaCraft.png", API_Util::PNG);
		API_Util::AddTexture("OptionsBG", "Resources/Images/backgroundPlain.png", API_Util::PNG);
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
		API_Util::AddGuiElementToContainer(ClientAPI::GetGuiContainer("Options"), "bg", "OptionsBG", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
		//ClientAPI::GetGuiContainer("Options")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }));

		//add logo
		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

		//add sliders
		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->AddGuiElement("musicSlider", new Slider(APIHelper::RectHelper(410, 460, 200, 20),
																			APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 0, 0, 255)),
																			APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 255, 255, 255))));

		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->AddGuiElement("SfxSlider", new Slider(APIHelper::RectHelper(410, 530, 200, 20),
			APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 0, 0, 255)),
			APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 255, 255, 255))));

		//add labels
		
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"), "Lbl_Options", "Options", { 450, 350, 200, 100 }, "OGWEAR", "White");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"), "Lbl_Music", "Music Volume:", { 430, 420, 200, 100 }, "Systema_22", "Black");
		API_Util::AddLabelToContainer(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"), "Lbl_SFX", "SFX Volume:", { 430, 490, 200, 100 }, "Systema_22", "Black");
		

		//add button
		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"), "returnToMainMenu", { 900, 720, 100, 30 }, "MedBtnNormal");

		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"),
			"returnToMainMenu", "Back", "Systema_11", "Black");

		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetButton("returnToMainMenu")->GetLabel()->SetPadding({ 29, 8, 0, 0 });

		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetButton("returnToMainMenu")->SubscribeOnMouseClick(ReturnToMainMenu);
		//

		API_Util::AddButtonToContainer(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"), "muteBtn", { 460, 590, 100, 30 }, "MedBtnNormal");

		API_Util::AddLabelToContainerButton(ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground"),
			"muteBtn", "Mute All", "Systema_11", "Black");

		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetButton("muteBtn")->GetLabel()->SetPadding({ 20, 8, 0, 0 });

		ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetButton("muteBtn")->SubscribeOnMouseClick(MuteAll);

		//Making options container not visible
		ClientAPI::GetGuiContainer("Options")->Active = false;
	}

	static void ReturnToMainMenu() {
		ClientAPI::GetGuiContainer("Options")->Active = false;
		ClientAPI::GetGuiContainer("MainMenu")->Active = true;
		ScreenFader::FadeOut();
	}

	static void MuteAll() {
		APIHelper::ToggleAllAudio();
		printf("Mute Button Pressed");
	}
};
