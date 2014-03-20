#include "ThreadedListener.h"
#include "ClientLiaison.h"
#include "NetServer.h"

using namespace ManaCraft::Networking;

SDL_Thread *listenThread;
std::vector<SDL_Thread*> ThreadedListener::threadedClients = std::vector<SDL_Thread*>();
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
			SDL_Thread* clientThread = SDL_CreateThread(Receive, "receiveThread", client);
			threadedClients.push_back(clientThread);
		}
	}
	return 0;
}

int ThreadedListener::Receive(void* data)
{
	while (true)
	{
		NetClient* client = (NetClient*)data;
		Packet* receivedPacket = client->Receive();
		if (receivedPacket != nullptr)
		{
			PacketFactory::CreateFromClientPacket(client->Receive());
		}
	}
	return 0;
}
