#include "ServerLiason.h"
#include "PacketFactory.h"
#include "ThreadedListener.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Client;
using namespace std;

NetClient* clientConnection = nullptr;
bool hasStarted = false;
SDL_Thread* ServerLiason::sendingThread;
SDL_Thread* ServerLiason::executeThread;
BlockingQueue<Packet*>* ServerLiason::sendingQueue;
BlockingQueue<CommandPacket*>* ServerLiason::executeQueue;

ServerLiason::ServerLiason() {
	// Set the connection
}

void ServerLiason::Start() {
	if (!hasStarted) {
		hasStarted = true;
		clientConnection = new NetClient("192.168.0.102", 27015);
		ThreadedListener* listener = new ThreadedListener(clientConnection, 5);

		sendingQueue = new BlockingQueue<Packet*>();
		executeQueue = new BlockingQueue<CommandPacket*>();
		
		sendingThread = SDL_CreateThread(SendingThread, "sending", NULL);
		if (sendingThread == NULL) {
			cout << "Failed to create Sending thread." << endl;
		}
		
		executeThread = SDL_CreateThread(ExecuteThread, "execute", NULL);
		if (executeThread == NULL) {
			cout << "Failed to create Sending thread." << endl;
		}

		// Send test packet
		std::string str = "wobbier";
		int payloadSize = str.length() + sizeof(__int8);
		std::vector<char> data = std::vector<char>(payloadSize);
		unsigned int pos = 0;
		Serialize::Int8(data, pos, payloadSize);
		pos += sizeof(__int8);
		for (unsigned int i = 0; i < str.length(); ++i) {
			data[pos + i] = str[i];
		}
		Packet* packet = new Packet(Networking::SEC_HEAD, Networking::LOGIN_PLAYER, data);
		SendPacket(packet);
	}
}

int ServerLiason::SendingThread(void* data) {
	while (hasStarted) { // While it's started run through the queue
		if (!sendingQueue->empty()) {
			try {
				std::cout << "Sending Packet..." << std::endl;
				Packet* packet = sendingQueue->pop();
				clientConnection->Send(*packet);
			}
			catch (ConnectionNotOpenException e) {
				cout << "Unable to send packet: " << e.what() << endl;
			}
		}
	}
	return 0;
}

int ServerLiason::ExecuteThread(void* data) {
	while (hasStarted) {
		if (!executeQueue->empty()) {
			CommandPacket* packet = executeQueue->pop();
			packet->Execute();
			delete packet;
			packet = nullptr;
		}
	}

	return 0;
}

void ServerLiason::CloseConnection() {
	hasStarted = false;
	clientConnection->Close();
}

void ServerLiason::SendPacket(Networking::Packet* packet) {
	if (hasStarted)
		sendingQueue->push(packet);
	else
		std::cout << "Unable to push due, liason between Client to Server has not been initialized" << std::endl;
}

void ServerLiason::Stop() {
	//listening
}