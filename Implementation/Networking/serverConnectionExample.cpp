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
	serverConn.Open();

	// Listen Loop
	while (true) {
		// Connection::Listen returns a pointer to a loaded connection with an accepted client
		Connection* clientConn = serverConn.Listen();

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

	std::cin.get();

	// Close your connections when you don't need them.
	serverConn.Close();

	return 0;
}