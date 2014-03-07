#ifndef SERVER_H
#define SERVER_H

//#include <SDL_mutex.h>
//#include <SDL_thread.h>
//#include <SDL_timer.h>
//#include <iostream>

#include <vector>

#include "BlockingQueue.h"
//#include "Connection.h"
#include "ClientLiaison.h"
//#include "Command_IntFloatProduct.h"
//#include "Command_TripleAFloat.h"
//#include "TestCommand.h"
//#include "Command_CreateNewGame.h"
#include "GameModel.h"

//#include "ServerIncludes.h"
//#include "ServerTester.h"
#include "ServerCommand.h"
#include "ServerCommandIncludes.h"

class Server {
private:
	bool running;
	
	unsigned int numRunningGames = 0;
	BlockingQueue<ServerCommand*> workQueue;
	
	

	void Init();


public:
	static const int MAX_GAMES;
	static std::vector<GameModel*> games;
	
	Server();
	~Server();

	void Run();
};

#endif
