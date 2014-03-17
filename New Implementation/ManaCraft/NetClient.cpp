#include "NetClient.h"
#include <iostream>
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
		const int secHead = payload.GetSecurityHeader();
		if (secHead == ManaCraft::Networking::SEC_HEAD) {
			// Send the data, store the length sent.
			int len = SDLNet_TCP_Send(mSocket, &payload.GetPayload()[0], payload.GetPayloadSize());
			// Might want to check against an expected length here?

			// If the length is < 0, there's a problem.
			if (len < 0) {
				for (int i = 0; i < 100; i++)
				{
					std::cout << SDLNet_GetError()[i];
				}
				printf("Client Send Error: %s", SDLNet_GetError());
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
		std::vector<char> buf;
		// Recieve some data.
		// Grab and check security header.
		std::vector<char> secHeader(4);
		int len = SDLNet_TCP_Recv(mSocket, &secHeader[0], 4);

		// If length < 0, error happened.
		if (len <= 0) {
			printf("Client Receive Error: %s", SDLNet_GetError());
			return nullptr;
		}
		__int32 header = Deserialize::Int32(secHeader, 0);

		// Ensure security
		if (header == SEC_HEAD) {
			// Grab and check length.
			std::vector<char> length(2);
			SDLNet_TCP_Recv(mSocket, &length[0], 2);

			__int16 dataLen = Deserialize::Int16(length, 0);

			// Get the protocol ID.
			std::vector<char> protocol(2);
			SDLNet_TCP_Recv(mSocket, &protocol[0], 2);

			__int16 protocolID = Deserialize::Int16(protocol, 0);
			// Can check against expected value now

			// Initialize the buffer and fill it with the data in Bytes
			// Dereferencing is done so we exit the function with a non-NULL Byte array.
			buf = std::vector<char>(dataLen);
			SDLNet_TCP_Recv(mSocket, &buf[0], dataLen);

			// Clean up previous security header pointer and re-use for the ending header
			secHeader.clear();
			secHeader = std::vector<char>(4);

			// Check the end header
			SDLNet_TCP_Recv(mSocket, &secHeader[0], 4);

			header = Deserialize::Int32(secHeader, 0);
			// If the ending header is valid, clean up and return the length of buf.
			if (header == SEC_HEAD) {
				// Clean up
				length.clear();
				secHeader.clear();

				// Return the length of data filled into the buffer.
				return new Packet(SEC_HEAD, protocolID, buf);
			}
			else {
				// Clean up
				length.clear();
				secHeader.clear();

				// Security header doesn't match, discard the data. It's dirty.
				buf.clear();

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