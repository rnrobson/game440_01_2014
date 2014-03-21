#include "ServerLiason.h"
#include "PacketFactory.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Client;
using namespace std;

NetClient* clientConnection = nullptr;
bool hasStarted = false;
BlockingQueue<ManaCraft::Networking::Packet> sendMsgQueue;

ServerLiason::ServerLiason() {
	// Set the connection
	clientConnection = new NetClient("192.168.2.18", 27015);
	
	// Open the connection
	int openState = clientConnection->Open();

	if (openState == 0) {
		cout << "The connection didn't open. Host: " << clientConnection->GetIP().host << " Port: " << clientConnection->GetIP().port << endl;
	}
	else {
		cout << "Client successfully connected on: " << clientConnection->GetIP().port << endl;
		hasStarted = true;

		listening = SDL_CreateThread(StaticListenToServer, "listening", this);
		if (listening == NULL) {
			cout << "Listening didn't create its thread." << endl;
		}

		sending = SDL_CreateThread(StaticSendToServer, "sending", this);
		if (sending == NULL) {
			cout << "Sending didn't create its thread." << endl;
		}
	}
}

void ServerLiason::Start() {
	if (!hasStarted)
		ServerLiason();
}


int ServerLiason::SendToServer() {
	sendMsgQueue = BlockingQueue<Packet>();

	while (hasStarted) { // While it's started run through the queue
		if (!sendMsgQueue.empty()) {
			/*Packet* p = nullptr;
			p = &sendMsgQueue.pop();

			clientConnection->Send(*p);
			
			TODO figure out a way around the packet's private constructor*/
		}
	}
	return 0;
}

int ServerLiason::StaticSendToServer(void* data) {
	return ((ServerLiason*)data)->SendToServer();
}


int ServerLiason::ListenToServer() {
	bool listen = true;

	while (listen) {
		Packet* packet = clientConnection->Receive();
		packet = PacketFactory::CreateFromServerPacket(packet);
		if (packet != nullptr) {
			std::cout << "Data received." << std::endl;
			packet->Execute();

			delete packet;
			packet = nullptr;
		}
	}
	CloseConnection();
	return 0;
}

int ServerLiason::StaticListenToServer(void* data) {
	return((ServerLiason*)data)->ListenToServer();
}


void ServerLiason::CloseConnection() {
	hasStarted = false;
	clientConnection->Close();
}

void ServerLiason::AddMessage(Packet* packet) {
	if (hasStarted)
		sendMsgQueue.push(*packet);
	else
		std::cout << "Unable to push due, liason between Client to Server has not been initialized" << std::endl;
}