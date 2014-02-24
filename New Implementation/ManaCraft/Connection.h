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
		private:
			std::string mUsername;
			IPaddress mIPAddress, *mRemoteIP; // Remote IP is for using Connection(TCPsocket& sock)
			TCPsocket mSocket;
			ConnectionStatus mStatus;
			SDL_Thread* listenerThread;

		public:
			/// <summary>[Connection]
			/// <para>Create a connection via a host and port.</para>
			/// </summary>
			Connection(char* host, Uint16 port);

			/// <summary>[Connection]
			/// <para>Create a connection via an existing TCPsocket.</para>
			/// <para>[TCPsocket sock] TODO: INFO REQ.</para>
			/// </summary>
			Connection(TCPsocket sock);

			/// <summary>[Open]
			/// <para>Attempt to open a socket using host and port provided to Connection.</para>
			/// <para>Throws a ConnectionOpenException if the connection is already open</para>
			/// <returns>Returns 1 on successful socket, 0 otherwise.</returns>
			/// </summary>
			int Open();

			/// <summary>[Listen]
			/// <para>A wrapper over SDL_TCP_Accept which provides a Connection when found.</para>
			/// <para>Throws a ConnectionNotServerTypeException if the connection is not set to act as a server</para>
			/// <returns>Returns a Connection pointer loaded with the accepted socket.</returns>
			/// </summary>
			Connection* Listen();

			/// <summary>[Close]
			/// <para>End the current socket connection.</para>
			/// <returns>Always returns 0.</returns>
			/// </summary>
			int Close();

			/// <summary>[ReceiveData]
			/// <para>Receive any data in the network buffer.</para>
			/// <para>[byte* buf] The local buffer to recieve the data into.</para>
			/// <para>Throws a ConnectionNotOpenException if the connection is not open.</para>
			/// <returns>Returns the length of the data received.</returns>
			/// </summary>
			int ReceiveData(byte** buf);

			/// <summary>[SendData]
			/// <para>**** Currently Unused **** </para>
			/// <para>Send data over the current network connection.</para>
			/// <para>[byte* payload] The byte buffer to be sent.</para>
			/// <return>Returns the length of the data sent.</return>
			/// </summary>
			int SendData(byte* payload);

			/// <summary>[SendData]
			/// <para>Send data over the current network connection.</para>
			/// <para>[Packet(ref) payload] A reference to the packet object holding the data to be sent.</para>
			/// <para>Throws a ConnectionNotOpenException if the connection is not open.</para>
			/// <returns>Returns the length of the data sent.</returns>
			/// </summary>
			int SendData(Packet& payload);

			/* Do we really need to store the username in the Connection class? */
			/// <summary>[GetUsername]
			/// <returns>Returns a std::string representation of the username associated with the Connection.</returns>
			/// </summary>
			std::string GetUsername() const;

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