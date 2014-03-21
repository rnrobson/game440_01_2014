#ifndef THREADEDLISTENER_H
#define THREADEDLISTENER_H

#include "ThreadPool.h"
#include "NetServer.h"
#include "NetClient.h"

namespace ManaCraft {
	namespace Networking {
		class ThreadedListener {
		public:
			/// <summary>[ThreadedListener]
			/// <para>Initializes the predefined server and creates an Accept thread for new clients.</para>
			/// <para>[NetServer* server] A predefined server that has not been Opened.</para>
			/// <para>[unsigned int numberOfThreads] The size of the thread pool.</para>
			/// </summary>
			ThreadedListener(NetServer* server, unsigned int numberOfThreads);

			/// <summary>[ThreadedListener]
			/// <para>Initializes the predefined client, creates a Listen thread for incoming packets, and sends them to the packet factory.</para>
			/// <para>[NetClient* client] A predefined client that has not been Opened.</para>
			/// <para>[unsigned int numberOfThreads] The size of the thread pool.</para>
			/// </summary>
			ThreadedListener(NetClient* client, unsigned int numberOfThreads);

			~ThreadedListener();

		private:
			SDL_Thread *acceptThread;
			static ThreadPool* threadPool;
			static int Accept(void*);
		};
	}
}
#endif