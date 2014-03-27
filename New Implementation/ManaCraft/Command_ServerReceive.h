#pragma once
#include "NetClient.h"
#include "PacketFactory.h"

using namespace ManaCraft::Networking;

class Command_ServerReceive : public CommandPacket {
private:
	NetClient* client;
	Packet nullPacket;

public:
	Command_ServerReceive(NetClient* _data) : CommandPacket(&nullPacket) {
		client = (NetClient*)_data;
	}

	~Command_ServerReceive() {
	}

	void Execute() {
		while (true) {
			Packet* receivedPacket = client->Receive();
			if (receivedPacket != nullptr) {
				PacketFactory::CreateFromClientPacket(receivedPacket);
			}
		}
	}
};