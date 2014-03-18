#include "ThreadedListener.h"
#include "ClientLiaison.h"
#include "NetServer.h"

using namespace ManaCraft::Networking;

SDL_Thread *listenThread;
std::vector<NetClient*> ThreadedListener::threadedClients = std::vector<NetClient*>();
NetServer server(27015);

ThreadedListener::ThreadedListener() {
	pool = new ThreadPool(5);
	
	listenThread = SDL_CreateThread(Listen, "listenThread", NULL);
	if (!listenThread) {
		std::cout << "Failed to create listen thread: " << SDL_GetError << std::endl;
	}
}

ThreadedListener::~ThreadedListener() {

}

int ThreadedListener::Listen(void*) {
	while (true) {
		NetClient* client = server.Listen();
		if (client) {
			std::cout << "Client Connected" << std::endl;
			threadedClients.push_back(client);
		}
	}
	return 0;
}

