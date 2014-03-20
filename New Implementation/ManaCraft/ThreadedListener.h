#ifndef THREADEDLISTENER_H
#define THREADEDLISTENER_H

#include "PacketFactory.h"
#include "ThreadPool.h"
#include "NetClient.h"
#include <vector>

namespace ManaCraft {
	namespace Networking {
		class ThreadedListener
		{
		public:
			ThreadedListener();
			~ThreadedListener();
		private:
			ThreadPool* pool;
			static int Listen(void*);
			static int Receive(void*);
			static std::vector<SDL_Thread*> threadedClients;
		};
	}
}
#endif