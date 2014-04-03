#ifndef SERVER_LIASON_H
#define SERVER_LIASON_H

#include <iostream>
#include "Packet.h"
#include "NetClient.h"
#include "BlockingQueue.h"
#include "Packet.h"
#include "PacketFactory.h"

namespace ManaCraft {
	namespace Client {
		class ServerLiason {
			private:
				static int SendingThread(void* data);
				static int ExecuteThread(void* data);
				static int StaticListenToServer(void* data);
				
				void CloseConnection();
				static BlockingQueue<Networking::Packet*>* sendingQueue;
				static BlockingQueue<CommandPacket*>* executeQueue;
				static SDL_Thread* sendingThread;
				static SDL_Thread* executeThread;

			public:
				ServerLiason();
				static void Start();
				static void Stop();
				static void SendPacket(Networking::Packet* packet);
		};
	}
}
#endif
