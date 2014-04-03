#include "MainMenu.h"
#include "ClientAPI.h"
#include "ClientSettings.h"
#include "Client.h"
#include "ScreenFader.h"

using namespace ManaCraft::Client;

MainMenu* MainMenu::instance;
MainMenu::NetIndicator MainMenu::netIndicator;

MainMenu::MainMenu()
:Page()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

	MainMenu::netIndicator = MainMenu::NetIndicator::Red;

	Load();
}

MainMenu* MainMenu::GetInstance()
{
	if (MainMenu::instance == nullptr) { MainMenu::instance = new MainMenu(); }

	return MainMenu::instance;
}

MainMenu::~MainMenu()
{
	Page::~Page();
}

void MainMenu::Load()
{	
	content->AddGuiContainer("Menu", new GuiContainer());
	content->AddGuiContainer("LoginPopup", new GuiContainer());

	LoadMainMenu();
	LoadLoginPopup();
}

void MainMenu::LoadMainMenu(){
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;
	const int MARGIN_Y = 40;
	const int BUTTON_SPC_Y = 20, BUTTON_SPC_X = 10;

	TTF_Font *systema = APIHelper::LoadFont("Resources/Fonts/9SYSTEMA.ttf", 22);

	ClientAPI::AddAudio("BtnAudio", APIHelper::LoadAudioFile("Resources/Audios/Menu/btnClick.ogg"));
	ClientAPI::AddFont("Systema", systema);
	
	//-- Convienient rects
	SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
	SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
	SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
	SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

	//-- Additional button rects
	SDL_Rect creditsBtnRect = APIHelper::RectHelper(SCREEN_WIDTH - medBtnRect.w - BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);

	// THIS CAUSES PROBLEMS:
	//content->AddGridLayer("Grid", new GridLayer());

	//-- Background
	content->GetGuiContainer("Menu")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
	content->GetGuiContainer("LoginPopup")->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	//-- Logo
	content->GetGuiContainer("Menu")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));
	content->GetGuiContainer("LoginPopup")->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

	//-- Buttons
	content->GetGuiContainer("Menu")->AddGuiContainer("BtnHolder", new GuiContainer());
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

	int xBtn, btnIndex = 0;

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->AddGuiElement("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->AddGuiElement("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->AddGuiElement("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->AddGuiElement("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->AddGuiElement("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("Menu")->AddGuiElement("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
	content->GetGuiContainer("Menu")->GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("Menu")->GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));

	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SubscribeOnMouseClick(MainMenu::Click_loginButton);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SubscribeOnMouseClick(MainMenu::Click_viewButton);

	if (MainMenu::netIndicator == MainMenu::NetIndicator::Green)
	{
		content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->Enabled = true;
	}
	else
	{
		content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->Enabled = false;
	}
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(MainMenu::Click_optionsButton);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SubscribeOnMouseClick(MainMenu::Click_tutorialButton);
	content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_quitButton);
	content->GetGuiContainer("Menu")->GetButton("CreditsBtn")->SubscribeOnMouseClick(MainMenu::Click_creditsButton);

	content->GetGuiContainer("Menu")->SetSfx1Audio(ClientAPI::GetAudio("BtnAudio"));
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

void MainMenu::LoadLoginPopup()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;


	SDL_Rect loginBtn = APIHelper::RectHelper(33, 0, 95, 35);
	SDL_Rect cancelBtn = APIHelper::RectHelper(190, 0, 95, 35);

	//-- Add the Login Bar
	content->GetGuiContainer("LoginPopup")->AddGuiElement("Background", new GuiElement(APIHelper::SolidColourTexture(300, 150, APIHelper::ColourHelper(0, 0, 0, 225)), APIHelper::RectHelper(10, -100, 300, 150)));
	content->GetGuiContainer("LoginPopup")->AddGuiElement("Username", new Label("Username", APIHelper::RectHelper(102, -80, 200, 100), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
	
	//-- Add Container for Elements
	content->GetGuiContainer("LoginPopup")->AddGuiContainer("ElementContainer", new GuiContainer());

	//-- Setup the text field
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->AddGuiElement("UsernameField", new TextField(APIHelper::RectHelper(35, -50, 250, 20), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("White")));
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetTextField("UsernameField")->CharacterLimit = 20;

	//-- Add in Login and Cancel Buttons
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->AddGuiElement("Login", new Button(ClientAPI::GetTexture("MedBtnNormal"), loginBtn));
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Login")->AddLabel("Login", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Login")->GetLabel()->SetPadding(APIHelper::RectHelper(12, 2, 0, 0));

	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->AddGuiElement("Cancel", new Button(ClientAPI::GetTexture("MedBtnNormal"), cancelBtn));
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Cancel")->AddLabel("Cancel", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Cancel")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));

	//-- Subscribe to Events
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Login")->SubscribeOnMouseClick(MainMenu::Click_LoginPopup_Login);
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetButton("Cancel")->SubscribeOnMouseClick(MainMenu::Click_LoginPopup_Cancel);
	//content->GetGuiContainer("LoginPopup")->SubscribeOnEscapeKeyPressed(LoginPopup::ButtonPress_Escape);
	//content->GetGuiContainer("LoginPopup")->SubscribeOnEnterKeyPressed(LoginPopup::ButtonPress_Enter);

	//-- Set Menu Position
	content->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->SetPosition(APIHelper::RectHelper((int)(SCREEN_WIDTH / 2.9), (int)(SCREEN_HEIGHT / 1.5), 0, 0));

	// Turn off
	content->GetGuiContainer("LoginPopup")->Active = false;
}


void MainMenu::Update(double time)
{
	Page::Update(time);
	if (MainMenu::netIndicator == MainMenu::NetIndicator::Green)
	{
		content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->Enabled = true;
	}
	else
	{
		content->GetGuiContainer("Menu")->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->Enabled = false;
	}
}

void MainMenu::Draw()
{
	Page::Draw();
}

void  MainMenu::PlayerLoggedIn(std::string _username)
{
	std::cout << "PlayerLoggedIn(_username)";
	ManaCraft::Client::Client::GetInstance()->Settings()->Username = _username;
	MainMenu::netIndicator = MainMenu::NetIndicator::Green;
}

//===================
//----------- Events
//===================

void MainMenu::OnEnterPressed()
{

}

void MainMenu::OnEscapePressed()
{

}

void MainMenu::Click_loginButton()
{
	std::cout << "Login to network.\n";
	//ClientAPI::GetGuiContainer("MainMenu")->Sfx1Play();
	//ClientAPI::GetGuiContainer("MainMenu")->Enabled = false;
	//ClientAPI::GetGuiContainer("LoginPopup")->Active = true;

	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = false;
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("LoginPopup")->Active = true;
}

void MainMenu::Click_viewButton()
{
	std::cout << "View saved games.\n";
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = false;
	//ViewGames::GetInstance()->GetContent()->Active = false;	// GetGuiContainer("ViewGames")->Active = true;

	ClientAPI::SetFocus(ViewGames::GetInstance());

	ScreenFader::GetInstance()->FadeOut();
}

void MainMenu::Click_optionsButton()
{
	std::cout << "Open options menu.\n";
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = false;
	//ClientAPI::GetGuiContainer("Options")->Active = true;
	ClientAPI::SetFocus(Options::GetInstance());

	ScreenFader::GetInstance()->FadeOut();
}

void MainMenu::Click_tutorialButton()
{
	std::cout << "Disabled until things are hooked up" << std::endl;
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = false;
	//ClientAPI::GetGuiContainer("GUI")->Active = true;
	//ClientAPI::GetGuiContainer("InGameGUI")->Active = true;


	ScreenFader::GetInstance()->FadeOut();
}

void MainMenu::Click_quitButton()
{
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	ClientAPI::ExitMainLoop();
}

void MainMenu::Click_creditsButton()
{
	std::cout << "Show credits.\n";
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	//MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = false;
	//ClientAPI::GetGuiContainer("Credits")->Active = true;

	ClientAPI::SetFocus(Credits::GetInstance());
	ScreenFader::GetInstance()->FadeOut();
}

void MainMenu::Click_LoginPopup_Cancel()
{
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = true; // Enabled
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("LoginPopup")->Active = false;
}

void MainMenu::Click_LoginPopup_Login()
{
	std::string _username = MainMenu::GetInstance()->GetContent()->GetGuiContainer("LoginPopup")->GetGuiContainer("ElementContainer")->GetTextField("UsernameField")->GetText();
	//NetworkCommands::LogIn(_username);
	MainMenu::GetInstance()->PlayerLoggedIn(_username);

	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Sfx1Play();
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("Menu")->Active = true; // Enabled
	MainMenu::GetInstance()->GetContent()->GetGuiContainer("LoginPopup")->Active = false;
}
