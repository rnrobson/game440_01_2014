#include "ThreadedListener.h"
#include "NetClient.h"
#include "NetServer.h"
#include "ThreadPool.h"
#include "Command_ClientReceive.h"
#include "Command_ServerReceive.h"

using namespace ManaCraft::Networking;

ThreadPool* ThreadedListener::threadPool = 0;

ThreadedListener::ThreadedListener(NetServer* server, unsigned int numberOfThreads) {
	if (!server->Open()) {
		std::cout << "Failed to initialize server on port: " << server->GetIP().port;
	}
	else {
		std::cout << "Listening...\n";
		ThreadedListener::threadPool = new ThreadPool(numberOfThreads);
		acceptThread = SDL_CreateThread(Accept, "listenThread", server);
		if (!acceptThread) {
			std::cout << "Failed to create listen thread: " << SDL_GetError << std::endl;
		}
	}
}

ThreadedListener::ThreadedListener(NetClient* client, unsigned int numberOfThreads) {
	if (!client->Open()) {
		std::cout << "Failed to connect to server: " << client->GetIP().host << ":" << client->GetIP().port;
	}
	else {
		ThreadedListener::threadPool = new ThreadPool(numberOfThreads);
		Command_ServerReceive* receiveFromServer = new Command_ServerReceive(client);
		threadPool->addWork(receiveFromServer);
	}
}

ThreadedListener::~ThreadedListener() {
	threadPool->shutdown();
}

int ThreadedListener::Accept(void* server) {
	NetServer* masterServer = (NetServer*)server;
	while (true) {
		NetClient* client = masterServer->Listen();
		if (client != nullptr) {
			std::cout << "Client Connected." << std::endl;
			Command_ClientReceive* receiveFromClient = new Command_ClientReceive(client);
			threadPool->addWork(receiveFromClient);
		}
	}
	return 0;
}