/**********************/
/*** CLIENT EXAMPLE ***/
/**********************/
// This example only demonstrates the functionality that is currently available
// via the Connection class. If it is not here, you can't use it yet.

#include "Connection.h"

#include <iostream>

#undef main // Just used for main clashes with SDL

using namespace ManaCraft::Networking;

int main(void) {
	// Don't forget to initialize SDL...
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	// Create a connection at host and port. This is a Connection 
	// waiting to be opened. It is not connected to anything yet.
	Connection clientConn("127.0.0.1", 25508);
	
	char c;
	std::cin >> c;

	if (c == 'o') {
		// Open (connect) to the host and port provided above.
		// Throw it (no pun intended) in a try... catch to prevent
		// invalid sockets by trying to open a connection that is
		// already opened.
		try {
			clientConn.Open();
		}
		catch (ConnectionOpenException coe) {
			std::cout << coe.what() << std::endl;
		}
	}

	// This array will likely contain serialized data types like ints and floats.
	char* data = "This message is data. Could also be a byte*.";

	// Fill a packet with the security header (accessed at the namespace below) as well
	// as whatever protocol command needed. The third parameter is the data in raw bytes.
	Packet packet(ManaCraft::Networking::SEC_HEAD, ManaCraft::Networking::SOME_PROTOCOL, data);

	// Send it off!
	// Throw it in a try... catch to be notified if an error (connection is not open) occurs.
	try {
		clientConn.SendData(packet);
	}
	catch (ConnectionNotOpenException cnoe) {
		std::cout << cnoe.what() << std::endl;
	}

	std::cin.get();

	// Close your connections when you're done with them!
	clientConn.Close();

	return 0;
}