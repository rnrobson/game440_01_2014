#ifndef THREADEDLISTENER_H
#define THREADEDLISTENER_H

#include "PacketFactory.h"
#include "ThreadPool.h"
#include "NetClient.h"
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
			static std::vector<NetClient*> clientList;
		};
	}
}
#endif