#pragma once
#include "PacketFactory.h"
#include "NetClient.h"
#include "Server.h"
#include "Client.h"

using namespace ManaCraft::Networking;

class Command_ClientReceive : public CommandPacket {
private:
	NetClient* client;
	Packet nullPacket;

public:
	Command_ClientReceive(NetClient* _data) : CommandPacket(&nullPacket) {
		client = (NetClient*)_data;
	}

	~Command_ClientReceive() {
	}

	void Execute() {
		while (true) {
			Packet* receivedPacket = client->Receive();
			if (receivedPacket != nullptr) {
				CommandPacket* commandPacket = PacketFactory::CreateFromServerPacket(receivedPacket);
				//ManaCraft::Client::Client::workQueue.push(commandPacket);
				std::cout << "Received packet from server: ";
				for (size_t i = 0; i < receivedPacket->GetDataLength(); i++) {
					std::cout << receivedPacket->GetData()[i];
				}
				std::cout << std::endl;
			}
		}
	}
};