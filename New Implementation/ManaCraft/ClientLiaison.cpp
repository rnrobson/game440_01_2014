#include "ClientLiaison.h"
#include "Serialize.h"
#include"ServerIncludes.h"
bool ClientLiaison::running = false;
Networking::Connection master(NULL, 25508);
std::vector<Networking::Connection*> ClientLiaison::connections = std::vector<Networking::Connection*>();
BlockingQueue<int> ClientLiaison::dataToClient = BlockingQueue<int>();
BlockingQueue<byte*> ClientLiaison::dataToWorker = BlockingQueue<byte*>();

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

	std::cout << std::endl << "Master connection attempted to open: " << i << std::endl;

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

			for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
				byte* buf = nullptr;
				int len;

				len = (*iter)->ReceiveData(&buf);


				if(len > 0) {
					std::cout << "Data received. Length of data: " << len << std::endl;
					std::cout << "Placing received data onto the Send to Worker queue" << std::endl;
					dataToWorker.push(buf);
				}
			}
		}
	}

	master.Close();

	return 0;
}

void ClientLiaison::SendToWorker() {
	bool sending = true;

	while(sending) {
		byte* buf = nullptr;
		int len;

		buf = dataToWorker.pop();

		__int16 protocolID = Networking::Deserialize::Int16(buf);
		std::cout << "Protocol: " << protocolID << std::endl;
		buf += sizeof(byte)* 2;
		std::cout << "Message: " << buf << std::endl;
	}
} //Test code to test receiving a message.

void ClientLiaison::CloseLiaison() {
	std::cout << "Closing master connection: " << master.Close() << std::endl;

	for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
		std::cout << "Closing connection: " << (*iter)->Close() << std::endl;
		delete *iter;
	}
}



