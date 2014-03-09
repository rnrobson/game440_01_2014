#include "ClientLiaison.h"
#include "Serialize.h"
#include"ServerIncludes.h"
bool ClientLiaison::running = false;
Networking::Connection master(NULL, 21025);
std::vector<Networking::Connection*> ClientLiaison::connections = std::vector<Networking::Connection*>();
BlockingQueue<int> ClientLiaison::dataToClient = BlockingQueue<int>();
BlockingQueue<Byte*> ClientLiaison::dataToWorker = BlockingQueue<Byte*>();

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
		std::cout << "Listening on port: 21025" << std::endl;
	} else {
		std::cout << "Failed to open master connecton." << std::endl;
	}

	while(listening) {
		try {
			Networking::Connection* connection = master.Listen();
			
			if(connection != NULL) {
				connections.push_back(connection);
				std::cout << "connected" << std::endl;

				for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
					Byte* buf = nullptr;
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
		catch(Networking::ConnectionNotServerTypeException e) {
			std::cout << e.what() << std::endl;
			std::cin.get();
		}
	}

	master.Close();

	return 0;
}

void ClientLiaison::SendToWorker() {
	bool sending = true;

	while(sending) {
		Byte* buf = nullptr;

		buf = dataToWorker.pop();

		Networking::CS_Protocol protocolID = (Networking::CS_Protocol)Networking::Deserialize::Int16(buf);

		buf += sizeof(Byte)* 2;

#pragma region Big Switch
		switch(protocolID) {
		default:
			break;
		case Networking::LOGIN_PLAYER:
			break;
		}
#pragma endregion

	}
}

void ClientLiaison::CloseLiaison() {
	std::cout << "Closing master connection: " << master.Close() << std::endl;

	for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
		std::cout << "Closing connection: " << (*iter)->Close() << std::endl;
		delete *iter;
	}
}



