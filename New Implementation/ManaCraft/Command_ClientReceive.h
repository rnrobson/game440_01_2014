#pragma once
#include "ServerCommand.h"
#include "NetClient.h"
#include "PacketFactory.h"

using namespace ManaCraft::Networking;

class Command_ClientReceive : public ServerCommand {
private:
	NetClient* client;

public:
	Command_ClientReceive(NetClient* _data) {
		data = _data;
		client = (NetClient*)data;
	}

	~Command_ClientReceive() {
	}

	void Execute() {
		while (true) {
			Packet* receivedPacket = client->Receive();
			if (receivedPacket != nullptr) {
				PacketFactory::CreateFromServerPacket(receivedPacket);
			}
		}
	}
};