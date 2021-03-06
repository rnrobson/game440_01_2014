#include "Options.h"
#include "MainMenu.h"

#include "ScreenFader.h"
#include "API_Util.h"
using namespace ManaCraft::Client;

Options* Options::instance;

Options::Options()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

	Load();
}

Options* Options::GetInstance()
{
	if (Options::instance == nullptr) { Options::instance = new Options(); }

	return Options::instance;
}

Options::~Options()
{
	Page::~Page();
}

void Options::Load()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;
	const int MARGIN_Y = 40;

	//add main container
	ClientAPI::AddGuiContainer("Options", content);
	content->AddGuiContainer("OptionsForeground", new GuiContainer());

	content->SetBackgroundAudio(ClientAPI::GetAudio("OptionsAudio"));
	content->SetSfx1Audio(ClientAPI::GetAudio("BtnAudio"));
	content->MusicPlay();

	//-- Convienient rects
	SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
	SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
	SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
	SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

	//add background
	API_Util::AddGuiElementToContainer(content, "bg", "BackgroundPlain", { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT });
	//ClientAPI::GetGuiContainer("Options")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }));

	//add logo
	content->GetGuiContainer("OptionsForeground")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

	//add sliders
	content->GetGuiContainer("OptionsForeground")->AddGuiElement("musicSlider", new Slider(APIHelper::RectHelper(410, 460, 200, 20),
		APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 0, 0, 255)),
		APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 255, 255, 255))));

	content->GetGuiContainer("OptionsForeground")->AddGuiElement("sfxSlider", new Slider(APIHelper::RectHelper(410, 530, 200, 20),
		APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 0, 0, 255)),
		APIHelper::SolidColourTexture(1, 1, APIHelper::ColourHelper(255, 255, 255, 255))));

	content->GetGuiContainer("OptionsForeground")->GetSlider("musicSlider")->SubscribeOnMouseUp(setMusicVolume);
	content->GetGuiContainer("OptionsForeground")->GetSlider("sfxSlider")->SubscribeOnMouseUp(setSfxVolume);


	//add labels

	API_Util::AddLabelToContainer(content->GetGuiContainer("OptionsForeground"), "Lbl_Options", "Options", { 450, 350, 200, 100 }, "OGWEAR", "White");
	API_Util::AddLabelToContainer(content->GetGuiContainer("OptionsForeground"), "Lbl_Music", "Music Volume:", { 430, 420, 200, 100 }, "Systema_22", "Black");
	API_Util::AddLabelToContainer(content->GetGuiContainer("OptionsForeground"), "Lbl_SFX", "SFX Volume:", { 430, 490, 200, 100 }, "Systema_22", "Black");

	//add button
	API_Util::AddButtonToContainer(content->GetGuiContainer("OptionsForeground"), "returnToMainMenu", { 900, 720, 100, 30 }, "MedBtnNormal");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("OptionsForeground"),
		"returnToMainMenu", "Back", "Systema_11", "Black");
	//

	API_Util::AddButtonToContainer(content->GetGuiContainer("OptionsForeground"), "muteBtn", { 460, 590, 100, 30 }, "MedBtnNormal");

	API_Util::AddLabelToContainerButton(content->GetGuiContainer("OptionsForeground"),
		"muteBtn", "Mute All", "Systema_11", "Black");

	content->GetGuiContainer("OptionsForeground")->GetButton("muteBtn")->GetLabel()->SetPadding({ 20, 8, 0, 0 });

	content->GetGuiContainer("OptionsForeground")->GetButton("muteBtn")->SubscribeOnMouseClick(MuteAll);

	content->GetGuiContainer("OptionsForeground")->GetButton("returnToMainMenu")->GetLabel()->SetPadding({ 29, 8, 0, 0 });

	content->GetGuiContainer("OptionsForeground")->GetButton("returnToMainMenu")->SubscribeOnMouseClick(ReturnToMainMenu);

	//Making options container not visible
	//content->Active = false;
}

void Options::Update(double time)
{
	Page::Update(time);
}

void Options::Draw()
{
	Page::Draw();
}

//===================
//----------- Events
//===================

void Options::OnEnterPressed()
{

}

void Options::OnEscapePressed()
{

}

void Options::ReturnToMainMenu() {
	Options::GetInstance()->GetContent()->Sfx1Play();

	//ClientAPI::GetGuiContainer("Options")->Active = false;
	//ClientAPI::GetGuiContainer("MainMenu")->Active = true;
	ClientAPI::SetFocus(MainMenu::GetInstance());

	ScreenFader::GetInstance()->FadeOut();
}

void Options::MuteAll() {
	Options::GetInstance()->GetContent()->Sfx1Play();

	APIHelper::ToggleAllAudio();
	printf("Mute Button Pressed");
}

void Options::setMusicVolume(SDL_MouseButtonEvent e) {
	int newMusicVolume = ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetSlider("musicSlider")->Value();
	APIHelper::SetMusicVolume(newMusicVolume);
}

void Options::setSfxVolume(SDL_MouseButtonEvent e) {
	int newSfxVolume = ClientAPI::GetGuiContainer("Options")->GetGuiContainer("OptionsForeground")->GetSlider("sfxSlider")->Value();
	APIHelper::SetSoundEffect1Volume(newSfxVolume);
}
