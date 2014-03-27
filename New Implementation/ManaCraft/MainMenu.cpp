#include "MainMenu.h"
#include "ScreenFader.h"
#include "ClientAPI.h"

MainMenu* MainMenu::instance;

MainMenu::MainMenu()
:Page()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

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

void MainMenu::Load(){
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
	ClientAPI::AddGuiContainer("MainMenu", content);
	content->Active = true;

	// THIS CAUSES PROBLEMS:
	//content->AddGridLayer("Grid", new GridLayer());

	//-- Background
	content->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("Background"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	//-- Logo
	content->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogo"), APIHelper::RectHelper(centerRect.x - 350, MARGIN_Y, 700, 300)));

	//-- Buttons
	content->AddGuiContainer("BtnHolder", new GuiContainer());
	content->GetGuiContainer("BtnHolder")->SetPosition(APIHelper::RectHelper(centerRect.x - longBtnRect.w / 2, centerRect.y, longBtnRect.w, 600));

	int xBtn, btnIndex = 0;

	content->GetGuiContainer("BtnHolder")->AddGuiElement("LoginBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetX();
	content->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->AddLabel("Login/Logout", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("BtnHolder")->AddGuiElement("ViewGamesBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetX();
	content->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->AddLabel("View Games", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("BtnHolder")->AddGuiElement("OptionsBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetX();
	content->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->AddLabel("Options", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("BtnHolder")->AddGuiElement("TutorialBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetX();
	content->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->AddLabel("Tutorial", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->GetGuiContainer("BtnHolder")->AddGuiElement("QuitBtn", new Button(ClientAPI::GetTexture("LongBtnNormal"), longBtnRect));
	xBtn = content->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetX();
	content->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SetPosition(xBtn, (btnIndex * (longBtnRect.h + BUTTON_SPC_Y)));
	content->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->AddLabel("Quit", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	btnIndex++;

	content->AddGuiElement("CreditsBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), creditsBtnRect));
	content->GetButton("CreditsBtn")->AddLabel("Credits", ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black"), true);
	content->GetButton("CreditsBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(2, 2, 0, 0));

	content->GetGuiContainer("BtnHolder")->GetButton("LoginBtn")->SubscribeOnMouseClick(MainMenu::Click_loginButton);
	content->GetGuiContainer("BtnHolder")->GetButton("ViewGamesBtn")->SubscribeOnMouseClick(MainMenu::Click_viewButton);
	content->GetGuiContainer("BtnHolder")->GetButton("OptionsBtn")->SubscribeOnMouseClick(MainMenu::Click_optionsButton);
	content->GetGuiContainer("BtnHolder")->GetButton("TutorialBtn")->SubscribeOnMouseClick(MainMenu::Click_tutorialButton);
	content->GetGuiContainer("BtnHolder")->GetButton("QuitBtn")->SubscribeOnMouseClick(MainMenu::Click_quitButton);
	content->GetButton("CreditsBtn")->SubscribeOnMouseClick(MainMenu::Click_creditsButton);


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


void MainMenu::Update(double time)
{
	Page::Update(time);
}

void MainMenu::Draw()
{
	Page::Draw();
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
	ClientAPI::GetGuiContainer("MainMenu")->Enabled = false;
	ClientAPI::GetGuiContainer("LoginPopup")->Active = true;
}

void MainMenu::Click_viewButton()
{
	std::cout << "View saved games.\n";
	ClientAPI::GetGuiContainer("MainMenu")->Active = false;
	ClientAPI::GetGuiContainer("ViewGames")->Active = true;
	ScreenFader::FadeOut();
}

void MainMenu::Click_optionsButton()
{
	std::cout << "Open options menu.\n";
	ClientAPI::GetGuiContainer("MainMenu")->Active = false;
	ClientAPI::GetGuiContainer("Options")->Active = true;
	ScreenFader::FadeOut();
}

void MainMenu::Click_tutorialButton()
{
	ClientAPI::GetGuiContainer("MainMenu")->Active = false;
	ClientAPI::GetGuiContainer("GUI")->Active = true;
	ClientAPI::GetGuiContainer("InGameGUI")->Active = true;
	ScreenFader::FadeOut();
}

void MainMenu::Click_quitButton()
{
	ClientAPI::ExitMainLoop();
}

void MainMenu::Click_creditsButton()
{
	std::cout << "Show credits.\n";
	ClientAPI::GetGuiContainer("MainMenu")->Active = false;
	ClientAPI::GetGuiContainer("Credits")->Active = true;
	ScreenFader::FadeOut();
}