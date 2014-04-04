#include "Credits.h"
#include "MainMenu.h"

#include "ScreenFader.h"
using namespace ManaCraft::Client;

Credits* Credits::instance;

Credits::Credits()
{
	content->SubscribeOnEnterKeyPressed(OnEnterPressed);
	content->SubscribeOnEnterKeyPressed(OnEscapePressed);

	Load();
}

Credits* Credits::GetInstance()
{
	if (Credits::instance == nullptr) { Credits::instance = new Credits(); }

	return Credits::instance;
}

Credits::~Credits()
{
	Page::~Page();
}

void Credits::Load()
{
	const int SCREEN_WIDTH = Window::Box().w;
	const int SCREEN_HEIGHT = Window::Box().h;
	const int LABEL_SPACE_Y = 25;
	const int BUTTON_SPC_Y = 10, BUTTON_SPC_X = 10;

	std::string clientStrings[9] = { "Andrew Godfroy", "Cassandra Siewert", "Christian Adao", "David Vo", "Geordie Powers", "Neil Schlachter", "Tyler Remazki", "Deanna Sowa" };
	std::string networkStrings[7] = { "Mitch Andrews", "Joshua O'Donnell", "Philip Diehl", "Dean Watts", "Suleyman Tahirli", "Brian Lefrancois", "Sarah Childs" };
	std::string serverStrings[7] = { "Rohun Banerji", "Justin Kan", "Jordan Kjaer", "Patrick Barahona-Griffiths", "Chris Devlieger", "Alex McCann", "Wayne Gauthier" };
	std::string databaseStrings[5] = { "Robert Evola", "Matt Mayo", "Vinny Crupi", "Kyle Nokes", "Jordan Hurst" };

	//-- Convienient rects
	SDL_Rect smallBtnRect = APIHelper::RectHelper(0, 0, 35, 35);
	SDL_Rect medBtnRect = APIHelper::RectHelper(0, 0, 95, 35);
	SDL_Rect longBtnRect = APIHelper::RectHelper(0, 0, 180, 35);
	SDL_Rect centerRect = APIHelper::RectHelper(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0);

	//-- Other rects
	SDL_Rect backBtnRect = APIHelper::RectHelper(BUTTON_SPC_X, SCREEN_HEIGHT - medBtnRect.h - BUTTON_SPC_Y, medBtnRect.w, medBtnRect.h);
	SDL_Rect clientRect = APIHelper::RectHelper(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 3, 0, 0);
	SDL_Rect networkRect = APIHelper::RectHelper(SCREEN_WIDTH - (SCREEN_WIDTH / 5) * 2, SCREEN_HEIGHT / 3, 0, 0);
	SDL_Rect serverRect = APIHelper::RectHelper(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 5, 0, 0);
	SDL_Rect databaseRect = APIHelper::RectHelper(SCREEN_WIDTH - (SCREEN_WIDTH / 5) * 2, SCREEN_HEIGHT / 2 + SCREEN_HEIGHT / 5, 0, 0);

	//-- Add in credits assets
	ClientAPI::AddGuiContainer("Credits", content);
	content->AddGuiElement("Background", new GuiElement(ClientAPI::GetTexture("BackgroundPlain"), APIHelper::RectHelper(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));
	content->AddGuiContainer("ClientCredits", new GuiContainer());
	content->AddGuiContainer("NetworkCredits", new GuiContainer());
	content->AddGuiContainer("ServerCredits", new GuiContainer());
	content->AddGuiContainer("DatabaseCredits", new GuiContainer());

	content->AddGuiElement("BackBtn", new Button(ClientAPI::GetTexture("MedBtnNormal"), backBtnRect));
	content->GetButton("BackBtn")->AddLabel("Back", ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("Black"), true);
	content->GetButton("BackBtn")->GetLabel()->SetPadding(APIHelper::RectHelper(7, 2, 0, 0));
	content->GetButton("BackBtn")->SubscribeOnMouseClick(Credits::Click_backButton);
	content->GetButton("BackBtn")->SubscribeOnEscapeKeyPressed(Credits::Click_backButton);

	content->AddGuiElement("Logo", new GuiElement(ClientAPI::GetTexture("GameLogoSmall"), APIHelper::RectHelper(SCREEN_WIDTH / 2 - 250, 0, 500, 250)));

	content->GetGuiContainer("ClientCredits")->AddGuiElement("ClientHeader", new Label("Client Team", APIHelper::RectHelper(clientRect.x, clientRect.y - LABEL_SPACE_Y * 2, clientRect.w, LABEL_SPACE_Y),
		ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	for (int i = 0; i < 9; i++)
	{
		content->GetGuiContainer("ClientCredits")->AddGuiElement("c" + i, new Label(clientStrings[i],
			APIHelper::RectHelper(clientRect.x, clientRect.y + (i * LABEL_SPACE_Y), clientRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	}

	content->GetGuiContainer("NetworkCredits")->AddGuiElement("NetworkHeader", new Label("Networking Team", APIHelper::RectHelper(networkRect.x, networkRect.y - LABEL_SPACE_Y * 2, networkRect.w, LABEL_SPACE_Y),
		ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	for (int i = 0; i < 7; i++)
	{
		content->GetGuiContainer("NetworkCredits")->AddGuiElement("n" + i, new Label(networkStrings[i],
			APIHelper::RectHelper(networkRect.x, networkRect.y + (i * LABEL_SPACE_Y), networkRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	}

	content->GetGuiContainer("ServerCredits")->AddGuiElement("ServerHeader", new Label("Server Team", APIHelper::RectHelper(serverRect.x, serverRect.y - LABEL_SPACE_Y * 2, serverRect.w, LABEL_SPACE_Y),
		ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	for (int i = 0; i < 7; i++)
	{
		content->GetGuiContainer("ServerCredits")->AddGuiElement("s" + i, new Label(serverStrings[i],
			APIHelper::RectHelper(serverRect.x, serverRect.y + (i * LABEL_SPACE_Y), serverRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	}

	content->GetGuiContainer("DatabaseCredits")->AddGuiElement("DatabaseHeader", new Label("Database Team", APIHelper::RectHelper(databaseRect.x, databaseRect.y - LABEL_SPACE_Y * 2, databaseRect.w, LABEL_SPACE_Y),
		ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	for (int i = 0; i < 5; i++)
	{
		content->GetGuiContainer("DatabaseCredits")->AddGuiElement("d" + i, new Label(databaseStrings[i],
			APIHelper::RectHelper(databaseRect.x, databaseRect.y + (i * LABEL_SPACE_Y), databaseRect.w, LABEL_SPACE_Y),
			ClientAPI::GetFont("Systema_22"), ClientAPI::GetColor("White")));
	}

	content->SetSfx1Audio(ClientAPI::GetAudio("BtnAudio"));
}

void Credits::Update(double time)
{
	Page::Update(time);
}

void Credits::Draw()
{
	Page::Draw();
}

//===================
//----------- Events
//===================

void Credits::OnEnterPressed()
{

}

void Credits::OnEscapePressed()
{

}

void Credits::Click_backButton()
{
	std::cout << "Back to main menu.\n";
	//ClientAPI::GetGuiContainer("Credits")->Sfx1Play();
	//ClientAPI::GetGuiContainer("Credits")->Active = false;
	//ClientAPI::GetGuiContainer("MainMenu")->Active = true;

	Credits::GetInstance()->GetContent()->Sfx1Play();
	ClientAPI::SetFocus(MainMenu::GetInstance());

	ScreenFader::GetInstance()->FadeOut();
}
