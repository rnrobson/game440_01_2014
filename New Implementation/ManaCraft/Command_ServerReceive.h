#pragma once
#include "ServerCommand.h"
#include "NetClient.h"
#include "PacketFactory.h"

using namespace ManaCraft::Networking;

class Command_ServerReceive : public ServerCommand {
private:
	NetClient* client;

public:
	Command_ServerReceive(NetClient* _data) {
		data = _data;
		client = (NetClient*)data;
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