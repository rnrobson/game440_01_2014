#pragma once

#include <vector>

#include "Protocol.h"
#include "Packet.h"
#include "NetClient.h"

namespace ManaCraft {
	namespace Networking {
		class NetBroadcaster {
		private:
			NetBroadcaster();

		public:
			static bool BroadcastMessage(std::vector<NetClient> clients, const ProtocolCommand cmd, Packet& data);
		};
	}
}