#include "ClientLiaison.h"
#include "Serialize.h"
#include"ServerIncludes.h"
#include "Packet.h"
bool ClientLiaison::running = false;
Networking::NetServer master(27015);
std::vector<Networking::NetClient*> ClientLiaison::connections = std::vector<Networking::NetClient*>();
BlockingQueue<int> ClientLiaison::dataToClient = BlockingQueue<int>();
BlockingQueue<Networking::Packet*> ClientLiaison::dataToWorker = BlockingQueue<Networking::Packet*>();

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
		std::cout << "Listening on port: " << master.GetIP().port << std::endl;
	} else {
		std::cout << "Failed to open master connecton." << std::endl;
	}

	while(listening) {
		try {
			Networking::NetClient* connection = master.Listen();
			
			if(connection != nullptr) {
				connections.push_back(connection);
				std::cout << "connected" << std::endl;

				for(auto iter = connections.begin(); iter != connections.end(); ++iter) {
					Networking::Packet* packet;

					packet = (*iter)->Receive();

					if(packet != nullptr) {
						std::cout << "Data received." << std::endl;
						std::cout << "Length of data : " << packet->GetDataLength() << std::endl;
						std::cout << "Protocol ID: " << packet->GetProtocolID() << std::endl;
						std::cout << "Packet Data: " << packet->GetData() << std::endl;
						std::cout << "Placing received data onto the Send to Worker queue" << std::endl;
						dataToWorker.push(packet);
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
		Networking::Packet* packet = nullptr;

		packet = dataToWorker.pop();

		Networking::CS_Protocol protocolID = (Networking::CS_Protocol)packet->GetProtocolID();

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



