#include "Client.h"
#include "ServerLiason.h"

using namespace ManaCraft;
//using namespace ManaCraft::Client;

ManaCraft::Client::Client* ManaCraft::Client::Client::instance;

void ManaCraft::Client::Client::InitSDLNet() {
	//Init SDL_net
	if (SDLNet_Init() == -1)
		std::cout << "Failed to initialize SDL_net, can't start connection" << std::endl;
	else {
		std::cout << "SDL_net was initialized properly" << std::endl;
		// If it was properly initialized, start the threads.
		try {
			// Comment this out if you're not testing networking
			ServerLiason::Start();
		}
		catch (ManaCraft::Networking::ConnectionOpenException e) {
			std::cout << "Unable to open socket: " << e.what() << std::endl;
		}
	}
}

ManaCraft::Client::Client::Client()
{
	////-- Initialize the API
	ClientAPI::Init();

	// Initialize SDLNet and start connection
	InitSDLNet();

	// Set the API Mode
	ClientAPI::SetAPIHandleMode(GuiAPIMode::ProgrammerHandleMode);

	// Set Custom Events
	ClientAPI::SubscribeCustomUpdate(Update);
	ClientAPI::SubscribeCustomDraw(Draw);
	ClientAPI::SubscribeEnterKeyFunc(OnEnterPressed);
	ClientAPI::SubscribeEscapeKeyFunc(OnEscapePressed);

	// Create the Settings
	settings = ClientSettings::GetInstance();

	// Load the Content
	LoadContent();

	// Set the Focus
	ClientAPI::SetFocus(mainMenu);

	//--Temporary asset loading
	SDL_Texture *_minionTexture = APIHelper::LoadPNGTexture("Resources/Sprites/MinionSS.png");
	SDL_Texture *_towerTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	SDL_Texture *_projectileTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	ClientAPI::AddTexture("MinionTex", _minionTexture);
	ClientAPI::AddTexture("TowerTex", _towerTexture);
	ClientAPI::AddTexture("ProjectileTex", _projectileTexture);
}
ManaCraft::Client::Client::~Client()
{
	//-- Quit the API and clean up our memory once the APIs Main loop is over
	ClientAPI::Quit();
}

void ManaCraft::Client::Client::LoadContent()
{
	//--Call individual load methods
	ScreenFader::GetInstance()->Load();

	mainMenu = MainMenu::GetInstance(); //MainMenu_O::Load();
	options = Options::GetInstance(); //Options::Load();
	credits = Credits::GetInstance(); //Credits::Load();
	gameLobby = GameLobby::GetInstance(); //GameLobby::Load();
	viewGames = ViewGames::GetInstance(); //ViewGames::Load();

	IngamePause::Load();
	LoginPopup::Load();
	GUI::Load();
	InGameGUI::Load();

}

void ManaCraft::Client::Client::Update(double time)
{
	//cout << "Entering Custom Update" << endl;
	ScreenFader::GetInstance()->Update(time);

	switch (GetInstance()->Settings()->GameState)
	{
	case GS_None:
		break;
	case GS_MainMenu:
		break;
	case GS_Options:
		break;
	case GS_Credits:
		break;
	case GS_ViewGames:
		break;
	case GS_Lobby:
		break;
	case GS_Tutorial:
		break;
	case GS_InGame:
		break;
	case GS_Paused:
		break;
	}
}

void ManaCraft::Client::Client::Draw()
{
	//cout << "Entering Custom Draw" << endl;
	ScreenFader::GetInstance()->Draw();

	switch (GetInstance()->Settings()->GameState)
	{
	case GS_None:
		break;
	case GS_MainMenu:
		break;
	case GS_Options:
		break;
	case GS_Credits:
		break;
	case GS_ViewGames:
		break;
	case GS_Lobby:
		break;
	case GS_Tutorial:
		break;
	case GS_InGame:
		break;
	case GS_Paused:
		break;
	}
}

void ManaCraft::Client::Client::OnEscapePressed()
{
	//IngamePause::Pause();
}

void ManaCraft::Client::Client::OnEnterPressed()
{
	Client::GetInstance()->Settings()->isHost = true;
}