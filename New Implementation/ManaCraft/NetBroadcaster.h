#pragma once

#include <vector>

#include "Protocol.h"
#include "Packet.h"

namespace ManaCraft {
	namespace Networking {
		class NetClient {
		public:
			int Send(Packet& payload) { printf("Test_Send\n"); return 1; }
		}; // Just for now... Remove when there is a concrete class

		class NetBroadcaster {
		private:
			NetBroadcaster();

		public:
			static bool BroadcastMessage(std::vector<NetClient> clients, const ProtocolCommand cmd, Packet& data);
		};
	}
}