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
		std::cout << "Failed to connect to server: " << client->GetIP().host << ":" << client->GetIP().port << std::endl;
	}
	else {
		std::cout << "Successfully connected to server: " << client->GetIP().host << ":" << client->GetIP().port << std::endl;
		ThreadedListener::threadPool = new ThreadPool(numberOfThreads);
		Command_ClientReceive* receiveFromServer = new Command_ClientReceive(client);
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
			Command_ServerReceive* receiveFromClient = new Command_ServerReceive(client);
			threadPool->addWork(receiveFromClient);

			// Test Packet
			/*std::string str = "What's good, client?";
			int payloadSize = str.length() + sizeof(__int8);
			std::vector<char> data = std::vector<char>(payloadSize);
			unsigned int pos = 0;
			Serialize::Int8(data, pos, payloadSize);
			pos += sizeof(__int8);
			for (unsigned int i = 0; i < str.length(); ++i) {
				data[pos + i] = str[i];
			}
			Packet* packet = new Packet(Networking::SEC_HEAD, Networking::LOGIN_PLAYER, data);
			masterServer->Send(*client, *packet);*/
		}
	}
	return 0;
}