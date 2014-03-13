#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <SDL_net.h>

#include "Packet.h"
#include "Serialize.h"
#include "Protocol.h"
#include "ConnectionException.h"

namespace ManaCraft {
	namespace Networking {

		enum ConnectionStatus {
			DISCONNECTED,
			CONNECTED
		};

		class Connection {
		protected:
			IPaddress mIPAddress, *mRemoteIP; // Remote IP is for using Connection(TCPsocket& sock)
			TCPsocket mSocket;
			ConnectionStatus mStatus;

		public:
			/// <summary>[Connection]
			/// <para>Create a connection via a host and port.</para>
			/// </summary>
			Connection(char* host, Uint16 port);

			/// <summary>[Connection]
			/// <para>Create a connection from an existing socket.</para>
			/// </summary>
			Connection(TCPsocket sock);

			/// <summary>[Open]
			/// <para>Attempt to open a socket using host and port provided to Connection.</para>
			/// <para>Throws a ConnectionOpenException if the connection is already open</para>
			/// <returns>Returns 1 on successful socket, 0 otherwise.</returns>
			/// </summary>
			int Open();

			/// <summary>[Close]
			/// <para>End the current socket connection.</para>
			/// <returns>Always returns 0.</returns>
			/// </summary>
			int Close();

			/// <summary>[GetIP]
			/// <returns>Returns the IPaddress object associated with the Connection.</returns>
			///</summary>
			IPaddress GetIP() const;

			/* Maybe we should encapsulate this further by only providing access to mSocket
			* by returning it from Open() */
			/// <summary>[GetSocket]
			/// <returns>Returns the TCPsocket associated with the Connection.</returns>
			/// </summary>
			TCPsocket GetSocket() const;

			/// <summary>[GetStatus]
			/// <returns>Returns the ConnectionStatus of the Connection.</returns>
			/// </summary>
			ConnectionStatus GetStatus() const;
		};
	}
}

#endif