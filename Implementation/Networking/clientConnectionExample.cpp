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
		clientConn.Open();
	}

	std::cin.get();

	// Close your connections when you're done with them!
	clientConn.Close();

	return 0;
}