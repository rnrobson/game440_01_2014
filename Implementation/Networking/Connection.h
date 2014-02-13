#pragma once

#include <string>
#include <SDL_net.h>

#include "Packet.h"

#ifdef NETWORKING_EXPORTS
#define NETWORKING_API __declspec(dllexport)
#else
#define NETWORKING_API __declspec(dllimport)
#endif

namespace ManaCraft {
	namespace Networking {

		NETWORKING_API enum ConnectionStatus {
			DISCONNECTED,
			CONNECTED
		};

		class NETWORKING_API Connection {
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
			/// <returns>Returns 1 on successful socket, 0 otherwise.</returns>
			/// </summary>
			int Open();

			/// <summary>[Listen]
			/// <para>A wrapper over SDL_TCP_Accept which provides a Connection when found.</para>
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
			/// <returns>Returns the length of the data sent.</returns>
			/// </summary>
			int SendData(Packet payload);

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