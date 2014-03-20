#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "ClientAPI.h"
#include "ClientSettings.h"

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

class Client
{
protected:
	Client();
public:
	static Client* GetInstance(){
		if (instance == nullptr) {
			instance = new Client();
		}

		return instance;
	}

	~Client();

	ClientSettings* Settings() { return settings; }

	void Run()
	{
		settings->GameState = MainMenu;

		//-- Start the APIs main loop
		ClientAPI::BeginMainLoop();
	}

private:
	static Client* instance;
	ClientSettings* settings;

	void LoadContent();
	
	static void Update(double time);
	static void Draw();
	static void OnEscapePressed();
	static void OnEnterPressed();

	void InitSDLNet(){
		//Init SDL_net
		if (SDLNet_Init() == -1)
			std::cout << "Failed to initialize SDL_net, can't start connection" << std::endl;
		else {
			std::cout << "SDL_net was initialized properly" << std::endl;
			// If it was properly initialized, start the threads.
			ManaCraft::Client::ServerLiason::Start();
		}
	}
};

#endif