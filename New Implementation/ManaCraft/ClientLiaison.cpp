#include "ClientLiaison.h"
#include "Serialize.h"

bool ClientLiaison::running = false;
Networking::Connection master(NULL, 25508);

std::vector<Networking::Connection*> ClientLiaison::connections = std::vector<Networking::Connection*>();
BlockingQueue<int> ClientLiaison::dataToClient = BlockingQueue<int>();
BlockingQueue<int> ClientLiaison::dataToWorker = BlockingQueue<int>();

SDL_Thread *incoming, *outgoing;

void ClientLiaison::InitLiaison() {
	running = true;
}

void ClientLiaison::Run() {
	InitLiaison();

	incoming = SDL_CreateThread(ClientListen, "Incoming", NULL);

	if(incoming == NULL) {
		std::cout << "Failed to create thread 'incoming': " << SDL_GetError << std::endl;
	}

	outgoing = SDL_CreateThread(SendToClient, "Outgoing", NULL);

	if(outgoing == NULL) {
		std::cout << "Failed to create thread 'outgoing': " << SDL_GetError << std::endl;
	}

	while(running) {
		SendToWorker();
	}

	CloseLiaison();
}

int ClientLiaison::SendToClient(void*) {
	while(false) {

	}
	return 0;
}

int ClientLiaison::ClientListen(void*) {
	bool listening = true;
	
	int i = master.Open();

	std::cout << "Master connection attempted to open: " << i << std::endl;

	if(i == 1) {
		std::cout << "Listening on port: 25508" << std::endl;
	} else {
		std::cout << "Failed to open master connecton." << std::endl;
	}

	while(listening) {
		Networking::Connection* connection = master.Listen();

		if(connection != NULL) {
			connections.push_back(connection);
			std::cout << "connected" << std::endl;
			listening = false;
		}
	}

	master.Close();

	return 0;
}

void ClientLiaison::SendToWorker() {
	/*for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
		byte* buf = nullptr;
		int len;

		len = (*iter)->ReceiveData(&buf);

		if(len > 0) {
			__int16 protocolID = Networking::DeserializeInt16(buf);
			buf += sizeof(byte)* 2;

			char* msg = buf;
			buf += sizeof(char)* len;

			std::cout << "Protocol ID: " << protocolID << " ";

			std::cout << "MESSAGE: [";
			for(__int16 i = 0; i < len; ++i) {
				std::cout << msg[i];
			}
			std::cout << "]";
		}
	}*/
} //Test code to test receiving a message.

void ClientLiaison::CloseLiaison() {
	std::cout << "Closing master connection: " << master.Close() << std::endl;

	for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
		std::cout << "Closing connection: " << (*iter)->Close() << std::endl;
		delete *iter;
	}
}



