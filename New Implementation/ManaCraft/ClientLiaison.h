#ifndef CLIENT_LIAISON_H
#define CLIENT_LIAISON_H

#include <SDL_mutex.h>
#include <SDL_thread.h>
#include <SDL_timer.h>
#include <iostream>
#include <vector>

#include "BlockingQueue.h"
#include "Connection.h"
#include "ConnectionException.h"
#include "NetClient.h"
#include "NetServer.h"
#include "Packet.h"
#include "PacketFactory.h"

using namespace ManaCraft;

		class ClientLiaison {
		private:
			static bool running;

			static Networking::NetServer* master;
			static std::vector<Networking::NetClient*> connections;
			static BlockingQueue<Networking::Packet*> dataToWorker;

			/// <summary>[InitLiaison]
			/// <para>Initialize the Client Liaison.</para>
			/// </summary>
			static void InitLiaison();

			/// <summary>[SendToClient]
			/// <para>Sends information to the appropriate clients/connections, via the appropriate thread.</para>
			/// </summary>
			static int SendToClient(void*);

			/// <summary>[ClientListen]
			/// <para>Uhh. Listen for connections.</para>
			/// </summary>
			static int ClientListen(void*);

			/// <summary>[SendToWorker]
			/// <para>Send data received from the current connections to the worker thread.</para>
			/// </summary>
			static void SendToWorker(); //Send the data to the worker

			/// <summary>[CloseLiaison]
			/// <para>Close all connections, shut down all threads.</para>
			/// </summary>
			static void CloseLiaison();

		public:
			/// <summary>[Run]
			/// <para>Runs the Client Liaison main loop.</para>
			/// <para>This is the only public function in the Liaison.</para>
			/// </summary>
			static void Run();
		};
	
#endif
