#define CLIENT_BUILD 1
#define SERVER_BUILD 0


#include <SDL.h>
#include <SDL_net.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#if CLIENT_BUILD
#include "ClientAPI.h"

//-- Networking
#include "ServerLiason.h"

//-- Helper Functions
#include "ScreenFader.h"

//-- Load Menus
#include "GameLobby.h"
#include "ViewGames.h"
#include "MainMenu.h"
#include "IngamePause.h"
#include "LoginPopup.h"
#include "Credits.h"
#include "Options.h"
#include "GUI.h"
#include "InGameGUI.h"

//-- Function Prototypes
void TransferControlToClient();
void CustomUpdate(double time);
void CustomDraw();
void OnEscapePressed();
void OnEnterPressed();
void InitSDLNet();
#endif

#if SERVER_BUILD
#include "Server.h"

void TransferControlToServer();
#endif

#if !CLIENT_BUILD && !SERVER_BUILD
#include "TestDatabase.h"
#endif

int main(int argc, char* argcs[]) {
#if CLIENT_BUILD
	TransferControlToClient();
#endif
#if SERVER_BUILD
	TransferControlToServer();
#endif
#if !CLIENT_BUILD && !SERVER_BUILD
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init failed." << std::endl;
	}
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags)) & imgFlags) {
		std::cout << "IMG_Init failed." << std::endl;
	}
	if (TTF_Init() != 0) {
		std::cout << "TTF_Init failed." << std::endl;
	}
	if (SDLNet_Init() != 0) {
		std::cout << "SDLNET_Init failed." << std::endl;
	}

	SDLNet_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	ManaCraft::Database::TestDatabase::runTests();

	std::cin.get();
#endif
	return 0;
}

#if CLIENT_BUILD
void TransferControlToClient() {
	////-- Initialize the API
	ClientAPI::Init();

	// Initialize SDLNet and start connection
	InitSDLNet();

	// Set Custom Events
	ClientAPI::SubscribeCustomUpdate(CustomUpdate);
	ClientAPI::SubscribeCustomDraw(CustomDraw);
	ClientAPI::SubscribeEnterKeyFunc(OnEnterPressed);
	ClientAPI::SubscribeEscapeKeyFunc(OnEscapePressed);

	//--Call individual load methods
	ScreenFader::Load();
	MainMenu::Load();
	IngamePause::Load();
	LoginPopup::Load();
	GUI::Load();
	Options::Load();
	Credits::Load();
	GameLobby::Load();
	ViewGames::Load();
	InGameGUI::Load();

	//--Temporary asset loading
	SDL_Texture *_minionTexture = APIHelper::LoadPNGTexture("Resources/Sprites/MinionSS.png");
	SDL_Texture *_towerTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	SDL_Texture *_projectileTexture = APIHelper::LoadPNGTexture("Resources/Tiles/sandAndRoads.png");
	ClientAPI::AddTexture("MinionTex", _minionTexture);
	ClientAPI::AddTexture("TowerTex", _towerTexture);
	ClientAPI::AddTexture("ProjectileTex", _projectileTexture);

	//==============================================================================================================================\\
		//==============================================================================================================================\\
		//-- Example of New GUI since Last ClientAPI change
	//ClientAPI::AddGuiContainer("cnt", new GuiContainer());

	////-- Checkboxes
	//ClientAPI::GetGuiContainer("cnt")->AddCheckbox("chk", new Checkbox({ 50, 50, 50, 50 }, { 255, 0, 0, 255 }, { 255, 255, 255, 255 }));
	//ClientAPI::GetGuiContainer("cnt")->GetCheckbox("chk")->Checked = true;

	////-- TextField Events
	//ClientAPI::GetGuiContainer("cnt")->AddTextField("txt field", new TextField(APIHelper::RectHelper(0, 0, 1000, 30), ClientAPI::GetFont("Systema"), ClientAPI::GetColor("Black")));
	//==============================================================================================================================\\
		//==============================================================================================================================\\
		

	//-- Start the APIs main loop
	ClientAPI::BeginMainLoop();

	//-- Quit the API once the APIs Main loop is over
	ClientAPI::Quit();
}

void CustomUpdate(double time)
{
	ScreenFader::Update(time);
	//cout << "Entering Custom Update" << endl;
}

void CustomDraw()
{
	ScreenFader::Draw();
	//cout << "Entering Custom Draw" << endl;
}

void OnEscapePressed()
{
	IngamePause::Pause();
}
void OnEnterPressed()
{
	
}

void InitSDLNet() {
	//Init SDL_net
	if (SDLNet_Init() == -1)
		std::cout << "Failed to initialize SDL_net, can't start connection" << std::endl;
	else {
		std::cout << "SDL_net was initialized properly" << std::endl;
		// If it was properly initialized, start the threads.
		ManaCraft::Client::ServerLiason::Start();
	}
}
#endif

#if SERVER_BUILD
void TransferControlToServer() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();
	Server *gameServer = new Server();
	gameServer->Run();
}
#endif