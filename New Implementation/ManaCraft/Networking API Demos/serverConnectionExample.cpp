/**********************/
/*** SERVER EXAMPLE ***/
/**********************/
// This example only demonstrates the functionality that is currently available
// via the Connection class. If it is not here, you can't use it yet.

#include "Connection.h"

#include <iostream>

#undef main  // Just used for main clashes with SDL

using namespace ManaCraft::Networking;

int main(void) {
	// Don't forget to initialize SDL...
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	// Create a connection locally (NULL host means SERVER socket)
	// Connections are not open by default.
	Connection serverConn(NULL, 25508);

	// Open the connection (be visible to the interwebs on the port provided above).
	// Prevent invalidating a socket by throwing this in a try... catch to do what you need
	// in case the connection is already open.
	try {
		serverConn.Open();
	}
	catch (ConnectionOpenException coe) {
		std::cout << coe.what() << std::endl;
	}

	// Listen Loop
	while (true) {
		// Connection::Listen returns a pointer to a loaded connection with an accepted client
		// try... catch prevents this action from happening on a non-server socket
		try {
			Connection* clientConn = serverConn.Listen();
		}
		catch (ConnectionNotServerTypeException cnste) {
			std::cout << cnste.what() << std::endl;
		}

		// The Connection will be NULL if there is noone connecting
		// and !NULL if there is a socket to be had.
		if (clientConn != NULL) {
			printf("Socket.\n");
			
			// Close your connections when you don't need them.
			clientConn->Close();
			
			// Clean up
			delete clientConn;
			break;
		}
		else {
			printf("No Socket.\n");
		}
	}

	/* The following can also be placed in a loop to listen for data on a socket */

	// Make an array of bytes to hold the data.
	byte* buf = nullptr;

	// Receive the data into buf. You need to pass by reference in order to make it out of the method
	// with a filled array.
	int len = clientConn->ReceiveData(&buf);

	// At this point, if the data was dirty, len will be > 0
	// but buf will be nullptr.

	if (len < 0) {
		// An error! It's already been printed to the console, but you can do further actions here.
	}
	else if (len == 0) {
		// No data was there to be received.
	}
	else {
		// Deal with the data, based on len.

		// The protocol command will be the first peice of data left after data is received.
		__int16 protocolCmd = DeserializeInt16(buf);
		// After deserialization, the pointer to the current block of the array must be incremented
		// equal to the size of the data read.
		buf += sizeof(short);

		// Read a regular int
		__int32 someIntValue = DeserializeInt32(buf);
		buf += sizeof(int);

		// Read a char message of length len
		int len = someLength;
		char msg[len];
		for (__int16 i = 0; i < len; ++i) {
			msg[i] = buf[i];
		}

		buf += sizeof(char) * len;

		delete buf; // Clean up the allocation, you've sent the data elsewhere now.
	}

	std::cin.get();

	// Close your connections when you don't need them.
	serverConn.Close();

	return 0;
}