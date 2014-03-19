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
#include "ThreadPool.h"
#include "LocalDB.h"

class Server {
private:
	bool running;
	unsigned int numRunningGames = 0;

	const Uint32 deltaTime = 1000;//setting to 1000 for testing - should be 16 for 60 fps
	Uint32 elapsedTime;//keeps track of time since SDL was initialized

	BlockingQueue<ServerCommand*> workQueue;
	GameManager* gameManager;
	ThreadPool* workCrew;
	LocalDB* localDB;

	const uint numWorkers = 3;

	void Init();
	void Update();
	int WorkOnQueue(void* data);

public:
	Server();
	~Server();

	void Run();
};

#endif
