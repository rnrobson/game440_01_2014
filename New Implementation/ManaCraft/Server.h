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
//#include "ServerCommand.h"
#include "ServerCommandIncludes.h"

//using namespace ManaCraft;

class Server {
private:
	bool running;
	BlockingQueue<ServerCommand*> workQueue;

	void Init();


public:

	Server();
	~Server();
};

#endif
