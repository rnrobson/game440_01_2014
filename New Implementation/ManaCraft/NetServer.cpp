#include "NetServer.h"
#include <iostream>
using namespace ManaCraft::Networking;

NetServer::NetServer(char* host, Uint16 port) : Connection(host, port) {

}

NetServer::NetServer(Uint16 port) : Connection(NULL, port) {

}

int NetServer::Send(NetClient client, Packet& payload) {
	// Make sure we're connected.
	if (client.GetSocket()) {
		// Check the security header being sent. Don't send if it's not valid.
		const int secHead = payload.GetSecurityHeader();
		if (secHead == ManaCraft::Networking::SEC_HEAD) {
			// Send the data, store the length sent.
			int len = SDLNet_TCP_Send(client.GetSocket(), &payload.GetPayload()[0], payload.GetPayloadSize());

			// Might want to check against an expected length here?

			// If the length is < 0, there's a problem.
			if (len < 0) {
				std::cout << SDLNet_GetError();
				printf("Error: %s", SDLNet_GetError());
			}
			else {
				// Return length of data successfully sent.
				return len;
			}
		}
	}
	else {
		throw ConnectionNotOpenException();
	}

	return 0;
}

NetClient* NetServer::Listen() {
	// Connection must be OPEN and set as a SERVER (host == NULL)
	if (mSocket && mIPAddress.host == NULL) {
		// Listen for a connection and grab it
		TCPsocket sock = NULL;
		sock = SDLNet_TCP_Accept(mSocket);

		// When we have a socket, wrap it in a Connection and return it.
		if (sock) {
			NetClient* newClient = new NetClient(sock);
			printf("Client Connected!");
			return newClient;
		}
		else
		{
			return nullptr;
		}
	}
	else {
		throw ConnectionNotServerTypeException();
	}
}