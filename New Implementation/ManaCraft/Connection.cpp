#include "Connection.h"

using namespace ManaCraft::Networking;

Connection::Connection(char* host, Uint16 port) {
	// Resolve the host and port provided
	if (SDLNet_ResolveHost(&mIPAddress, host, port) < 0) {
		printf("Unable to resolve host: %s\n", SDLNet_GetError());
		exit(1); // Should be changed
	}

	// Connections begin CLOSED.
	mStatus = DISCONNECTED;
}

Connection::Connection(TCPsocket sock) {
	if (sock) {
		// This constructor is primarily used as the way of returning accepted sockets
		// as a Connection object
		mSocket = sock;

		// Get the address information of the socket
		mRemoteIP = SDLNet_TCP_GetPeerAddress(mSocket);
		mStatus = ConnectionStatus::CONNECTED;
	}
}

int Connection::Open() {
	if (mSocket) {
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

Connection* Connection::Listen() {
	// Connection must be OPEN and set as a SERVER (host == NULL)
	if (mSocket && mIPAddress.host == NULL) {
		// Listen for a connection and grab it
		TCPsocket sock = SDLNet_TCP_Accept(mSocket);

		// When we have a socket, wrap it in a Connection and return it.
		if (sock) {
			return new Connection(sock);
		}
	}
	else {
		throw ConnectionNotServerTypeException();
	}

	// If all else fails, return NULL
	return nullptr;
}

int Connection::ReceiveData(byte** buf) {
	if (mSocket) {
		// Recieve some data.
		// Grab and check security header.
		byte* secHeader = new char[4];
		int len = SDLNet_TCP_Recv(mSocket, secHeader, 4);

		// This should be checked and fixed if possible.
		// Copy from received array into local array to remove unwanted characters
		// at end of secHeader.
		byte header[4];
		for (__int16 i = 0; i < 4; ++i) {
			header[i] = secHeader[i];
		}

		// If length < 0, error happened.
		if (len < 0) {
			printf("Error: %s", SDLNet_GetError());
			return len;
		}

		// Ensure security
		if (header[0] == SEC_HEAD[0] && header[1] == SEC_HEAD[1] && header[2] == SEC_HEAD[2] && header[3] == SEC_HEAD[3]) {
			// Grab and check length.
			byte* length = new char[2];
			SDLNet_TCP_Recv(mSocket, length, 2);

			__int16 dataLen = DeserializeInt16(length);
			// Can check against expected value now

			// Initialize the buffer and fill it with the data in bytes
			// Dereferencing is done so we exit the function with a non-NULL byte array.
			*buf = new byte[dataLen];
			SDLNet_TCP_Recv(mSocket, *buf, dataLen + 2);

			// Clean up previous security header pointer and re-use for the ending header
			delete[] secHeader;
			secHeader = new char[4];

			// Check the end header
			SDLNet_TCP_Recv(mSocket, secHeader, 4);

			// Copy again to truncate unwanted characters from secHeader
			for (__int16 i = 0; i < 4; ++i) {
				header[i] = secHeader[i];
			}

			// If the ending header is valid, clean up and return the length of buf.
			if (header[0] == SEC_HEAD[0] && header[1] == SEC_HEAD[1] && header[2] == SEC_HEAD[2] && header[3] == SEC_HEAD[3]) {
				// Clean up
				delete[] length;
				delete[] secHeader;

				// Return the length of data filled into the buffer.
				return dataLen;
			}
			else {
				// Security header doesn't match, discard the data. It's dirty.
				delete[] secHeader;
				delete[] *buf;
				*buf = nullptr;

				return dataLen;
			}
		}
	}
	else {
		throw ConnectionNotOpenException();
	}

	// If something goes wrong, return 0
	return 0;
}

/****** CURRENTLY UNUSED ******/
int Connection::SendData(byte* payload) {
	// Send data over mSocket.
	// Coming soon to a repo near you.
	return 0;
}

int Connection::SendData(Packet& payload) {
	// Make sure we're connected.
	if (mSocket) {
		// Check the security header being sent. Don't send if it's not valid.
		const byte* secHead = payload.GetSecurityHeader();
		if (secHead == ManaCraft::Networking::SEC_HEAD) {
			// Send the data, store the length sent.
			int len = SDLNet_TCP_Send(mSocket, payload.GetPayload(), payload.PayloadSize());

			// Might want to check against an expected length here?

			// If the length is < 0, there's a problem.
			if (len < 0) {
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

std::string Connection::GetUsername() const {
	return mUsername;
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