#pragma once

#include "Connection.h"
#include "NetClient.h"
#include <vector>

namespace ManaCraft {
	namespace Networking {

		class NetServer : public Connection {
		public:
			NetServer(char* host, Uint16 port);

			NetServer(Uint16 port);

			/// <summary>[Listen]
			/// <para>A wrapper over SDL_TCP_Accept which provides a Connection when found.</para>
			/// <para>Throws a ConnectionNotServerTypeException if the connection is not set to act as a server</para>
			/// <returns>Returns a Connection pointer loaded with the accepted socket.</returns>
			/// </summary>
			NetClient* Listen();

			/// <summary>[Send]
			/// <para>Send data over the current network connection.</para>
			/// <para>[Packet(ref) payload] A reference to the packet object holding the data to be sent.</para>
			/// <para>Throws a ConnectionNotOpenException if the connection is not open.</para>
			/// <returns>Returns the length of the data sent.</returns>
			/// </summary>
			int Send(NetClient client, Packet& payload);
		};
	}
}