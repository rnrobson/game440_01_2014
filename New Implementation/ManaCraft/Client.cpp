#include "Client.h"

Client* Client::instance;


void Client::InitSDLNet(){
	//Init SDL_net
	if (SDLNet_Init() == -1)
		std::cout << "Failed to initialize SDL_net, can't start connection" << std::endl;
	else {
		std::cout << "SDL_net was initialized properly" << std::endl;
		// If it was properly initialized, start the threads.
		try {
			ManaCraft::Client::ServerLiason::Start();
		}
		catch (ManaCraft::Networking::ConnectionOpenException e) {
			std::cout << "Unable to open socket: " << e.what() << std::endl;
		}
	}
}

Client::Client()
{
	////-- Initialize the API
	ClientAPI::Init();

	// Initialize SDLNet and start connection
	InitSDLNet();

	// Set the API Mode
	ClientAPI::SetAPIHandleMode(GuiAPIMode::APIHandleMode);

	// Set Custom Events
	ClientAPI::SubscribeCustomUpdate(Update);
	ClientAPI::SubscribeCustomDraw(Draw);
	ClientAPI::SubscribeEnterKeyFunc(OnEnterPressed);
	ClientAPI::SubscribeEscapeKeyFunc(OnEscapePressed);

	// Create the Settings
	settings = new ClientSettings();

	// Load the Content
	LoadContent();

	//--Temporary asset loading
	SDL_Texture *_minionTexture = APIHelper::LoadPNGTexture("Resources/Sprites/MinionSS.png");
	SDL_Texture *_towerTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	SDL_Texture *_projectileTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	ClientAPI::AddTexture("MinionTex", _minionTexture);
	ClientAPI::AddTexture("TowerTex", _towerTexture);
	ClientAPI::AddTexture("ProjectileTex", _projectileTexture);
}
Client::~Client()
{
	//-- Quit the API and clean up our memory once the APIs Main loop is over
	ClientAPI::Quit();
}

void Client::LoadContent()
{
	//--Call individual load methods
	ScreenFader::Load();

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

void Client::Update(double time)
{
	//cout << "Entering Custom Update" << endl;
	ScreenFader::Update(time);

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

void Client::Draw()
{
	//cout << "Entering Custom Draw" << endl;
	ScreenFader::Draw();

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

void Client::OnEscapePressed()
{
	//IngamePause::Pause();
}

void Client::OnEnterPressed()
{
	Client::GetInstance()->Settings()->isHost = true;
}