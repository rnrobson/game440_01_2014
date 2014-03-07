#ifndef SERVER_H
#define SERVER_H

//#include <SDL_mutex.h>
//#include <SDL_thread.h>
//#include <SDL_timer.h>
//#include <iostream>

#include <vector>
#include "BlockingQueue.h"
#include "ClientLiaison.h"
#include "GameModel.h"
#include "GameManager.h"
#include "ServerCommand.h"
#include "ServerCommandIncludes.h"
#include "ServerTester.h"

class Server {
private:
	bool running;
	unsigned int numRunningGames = 0;
	BlockingQueue<ServerCommand*> workQueue;
	GameManager* gameManager;
	void Init();

public:
	Server();
	~Server();

	void Run();
};

#endif
