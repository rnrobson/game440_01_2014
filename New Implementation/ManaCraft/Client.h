#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "ClientAPI.h"
#include "API_Util.h"
#include "ClientSettings.h"

//-- Networking
#include "ServerLiason.h"

//-- Helper Functions
#include "ScreenFader.h"

//-- Load Menus
#include "MainMenu.h"
#include "Credits.h"
#include "Options.h"
#include "GameLobby.h"
#include "ViewGames.h"
#include "GamePage.h"

namespace ManaCraft {
	namespace Client {
		class Client {
		protected:
			Client();

			MainMenu* mainMenu;
			Credits* credits;
			Options* options;
			GameLobby* gameLobby;
			ViewGames* viewGames;
			GamePage* gamePage;

		public:
			static Client* GetInstance() {
				if (instance == nullptr) {
					instance = new Client();
				}

				return instance;
			}

			~Client();

			ClientSettings* Settings() { return settings; }

			void Run() {
				settings->GameState = GS_MainMenu;

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

			void InitSDLNet();
		};
	}
}
#endif