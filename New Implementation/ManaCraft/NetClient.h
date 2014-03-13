#pragma once

#include "Connection.h"

namespace ManaCraft {
	namespace Networking {

		class NetClient : public Connection {
		private:
			std::string mUsername;

			NetClient();
		public:
			/// <summary>[NetClient]
			/// <para>Create a connection to the server socket.</para>
			/// </summary>
			NetClient(char* host, Uint16 port);

			/// <summary>[NetClient]
			/// <para>Create a connection from an existing socket.</para>
			/// </summary>
			NetClient(TCPsocket socket);

			/// <summary>[Send]
			/// <para>Send data over the current network connection.</para>
			/// <para>[Packet(ref) payload] A reference to the packet object holding the data to be sent.</para>
			/// <para>Throws a ConnectionNotOpenException if the connection is not open.</para>
			/// <returns>Returns the length of the data sent.</returns>
			/// </summary>
			int Send(Packet& payload);

			/// <summary>[Receive]
			/// <para>Receive any data in the network buffer.</para>
			/// <para>[byte* buf] The local buffer to recieve the data into.</para>
			/// <para>Throws a ConnectionNotOpenException if the connection is not open.</para>
			/// <returns>Returns the length of the data received.</returns>
			/// </summary>
			Packet* Receive();

			/// <summary>[GetUsername]
			/// <returns>Returns a std::string representation of the username associated with the NetSender.</returns>
			/// </summary>
			std::string GetUsername() const;
		};

	}
}