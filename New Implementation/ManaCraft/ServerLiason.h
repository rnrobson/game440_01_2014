#ifndef SERVER_LIASON_H
#define SERVER_LIASON_H

#include <iostream>
#include "Packet.h"

namespace ManaCraft {
	namespace Client {
		class ServerLiason {
			private:
				static int SendToServer(void*);
				static int ListenToServer(void*);
				static void CloseConnection();
				static void ProcessData(ManaCraft::Networking::Packet* packet);

			public:
				static void Start();
		};
	}
}
#endif
