#ifndef SERVER_LIASON_H
#define SERVER_LIASON_H

#include <iostream>
#include "Packet.h"
#include "NetClient.h"
#include "BlockingQueue.h"

namespace ManaCraft {
	namespace Client {
		class ServerLiason {
			private:
				static int StaticSendToServer(void* data);
				int SendToServer();
				static int StaticListenToServer(void* data);
				int ListenToServer();
				void CloseConnection();

				SDL_Thread* listening;
				SDL_Thread* sending;
				

			public:
				ServerLiason();
				static void Start();
				static void AddMessage(ManaCraft::Networking::Packet* packet);
		};
	}
}
#endif
