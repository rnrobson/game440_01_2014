#ifndef SERVER_H
#define SERVER_H

#include <SDL_mutex.h>
#include <SDL_thread.h>
#include <SDL_timer.h>
#include <iostream>
#include <vector>

#include "BlockingQueue.h"
#include "Connection.h"
#include "WorkItem.h"
#include "GameModel.h"
//#include "ServerCommand.h"
#include "ServerCommandIncludes.h"
//using namespace ManaCraft;

class Server {
private:
	bool running;
	const size_t MAX_GAMES = 10;
	BlockingQueue<ServerCommand*> workQueue;
	vector<GameModel*> games;

	void Init();


public:

	Server();
	~Server();
};

#endif
