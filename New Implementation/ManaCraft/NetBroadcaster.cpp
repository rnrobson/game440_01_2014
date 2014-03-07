#include "NetBroadcaster.h"

using namespace ManaCraft::Networking;

NetBroadcaster::NetBroadcaster() {

}

bool NetBroadcaster::BroadcastMessage(std::vector<NetClient> clients, const ProtocolCommand cmd, Packet& data) {
	for (size_t i = 0; i < clients.size(); ++i) {
		int sentLen = clients[i].Send(data);

		if (sentLen < 0) {
			return false;
		}
	}

	return true;
}