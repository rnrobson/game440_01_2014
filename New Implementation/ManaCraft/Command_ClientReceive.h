#pragma once
#include "PacketFactory.h"
#include "NetClient.h"
#include "PacketFactory.h"

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
				PacketFactory::CreateFromServerPacket(receivedPacket);
			}
		}
	}
};