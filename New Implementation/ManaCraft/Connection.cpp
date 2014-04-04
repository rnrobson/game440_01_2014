#include "Connection.h"

using namespace ManaCraft::Networking;

Connection::Connection(char* host, Uint16 port) {
	printf("Connection constructor called with host %s and port %i\n", host, port);
	// Resolve the host and port provided
	if (SDLNet_ResolveHost(&mIPAddress, host, port) < 0) {
		printf("Unable to resolve host: %s\n", SDLNet_GetError());
		exit(1); // Should be changed
	}

	// Connections begin CLOSED.
	mStatus = DISCONNECTED;
}

Connection::Connection(TCPsocket socket) : mSocket(socket) {
	// Connections begin CLOSED.
	mStatus = DISCONNECTED;
}

int Connection::Open() {
	if (!mSocket) {
		throw ConnectionOpenException();
	}
	else {

		// Try to open a socket with IP data stored in mIPAddress
		mSocket = SDLNet_TCP_Open(&mIPAddress);

		// On success, change status to CONNECTED and return true
		if (mSocket) {
			mStatus = CONNECTED;
			return 1;
		}
	}

	// If all else fails, return false
	return 0;
}

int Connection::Close() {
	// Simply close the socket and set the connection status to DISCONNECTED.
	SDLNet_TCP_Close(mSocket);
	mStatus = DISCONNECTED;

	return 0;
}

IPaddress Connection::GetIP() const {
	// If we have created a connection via an incoming socket,
	// return the remoteIP info instead of the local IP.
	if (mIPAddress.port == NULL) {
		return *mRemoteIP;
	}

	// Otherwise return the local IP information.
	return mIPAddress;
}

TCPsocket Connection::GetSocket() const {
	return mSocket;
}

ConnectionStatus Connection::GetStatus() const {
	return mStatus;
}