#include "NetClient.h"

using namespace ManaCraft::Networking;

NetClient::NetClient(char* host, Uint16 port) : Connection(host, port) {

}

NetClient::NetClient(TCPsocket socket) : Connection(socket) {

}
NetClient::NetClient() : Connection(NULL) {

}

std::string NetClient::GetUsername() const {
	return mUsername;
}

int NetClient::Send(Packet& payload) {
	// Make sure we're connected.
	if (mSocket) {
		// Check the security header being sent. Don't send if it's not valid.
		const Byte* secHead = payload.GetSecurityHeader();
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

Packet* NetClient::Receive() {
	if (mSocket) {
		Byte* buf = 0;
		// Recieve some data.
		// Grab and check security header.
		Byte* secHeader = new char[4];
		int len = SDLNet_TCP_Recv(mSocket, secHeader, 4);

		// This should be checked and fixed if possible.
		// Copy from received array into local array to remove unwanted characters
		// at end of secHeader.
		Byte header[4];
		for (__int16 i = 0; i < 4; ++i) {
			header[i] = secHeader[i];
		}

		// If length < 0, error happened.
		if (len < 0) {
			printf("Error: %s", SDLNet_GetError());
			return nullptr;
		}

		// Ensure security
		if (header[0] == SEC_HEAD[0] && header[1] == SEC_HEAD[1] && header[2] == SEC_HEAD[2] && header[3] == SEC_HEAD[3]) {
			// Grab and check length.
			Byte* length = new char[2];
			SDLNet_TCP_Recv(mSocket, length, 2);

			__int16 dataLen = Deserialize::Int16(length);

			// Get the protocol ID.
			Byte* protocol = new char[2];
			SDLNet_TCP_Recv(mSocket, protocol, 2);

			__int16 protocolID = Deserialize::Int16(length);
			// Can check against expected value now

			// Initialize the buffer and fill it with the data in Bytes
			// Dereferencing is done so we exit the function with a non-NULL Byte array.
			buf = new Byte[dataLen];
			SDLNet_TCP_Recv(mSocket, buf, dataLen);

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
				return new Packet(SEC_HEAD, protocolID, buf);
			}
			else {
				// Clean up
				delete[] length;
				delete[] secHeader;

				// Security header doesn't match, discard the data. It's dirty.
				delete[] buf;
				buf = nullptr;

				return nullptr;
			}
		}
	}
	else {
		throw ConnectionNotOpenException();
	}

	// If something goes wrong, return a null pointer
	return nullptr;
}