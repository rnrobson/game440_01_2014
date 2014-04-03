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

	static BlockingQueue<CommandPacket*> workQueue;

	GameManager* gameManager;
	ThreadPool* workCrew; //obsolte - use Server::AddWork()
	LocalDB* localDB;
	ClientLiaison* clientLiaison;

	const uint numWorkers = 3;

	/// <summary>[Init]
	/// <para>Initliazes variables and data in server</para>
	/// </summary>
	void Init();
	void Update();
	int WorkOnQueue(void* data);

public:
	
	Server();
	~Server();
	/// <summary>[Run]
	/// <para>Starts running the server - starts update loop and works on the queue</para>
	/// </summary>
	void Run();
	/// <summary>[AddWork]
	/// <para>Static method to add commands to the server's work queue</para>
	/// </summary>
	static void AddWork(CommandPacket* command);
	/// <summary>[Shutdown]
	/// <para>clears memory and Shuts down the server</para>
	/// </summary>
	void Shutdown();
};

#endif
