#define CLIENT_BUILD 0
#define SERVER_BUILD 1


#include <SDL.h>
#include <SDL_net.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#if CLIENT_BUILD
#include "Client.h"
#include "ClientAPI.h"

//-- Function Prototypes
void TransferControlToClient();
#endif

#if SERVER_BUILD
#include "Server.h"

void TransferControlToServer();
#endif

#if !CLIENT_BUILD && !SERVER_BUILD
#include "TestDatabase.h"
#include "TestLocalDB.h"
#include "Serialize.h"
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

	/*ManaCraft::Testbed::TestLocalDB *testLocalDB;
	testLocalDB = new ManaCraft::Testbed::TestLocalDB(10);

	testLocalDB->Run();

	delete testLocalDB;*/

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
	ManaCraft::Client::Client* client = ManaCraft::Client::Client::GetInstance();
	client->Run();
	delete client;
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