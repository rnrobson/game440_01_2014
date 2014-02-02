//*
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <SDL_timer.h>
#include <SDL_thread.h>

#include "BlockingQueue.h"
#include "TempCommands.h"

int WorkerThread(void *ptr);
int DbThread(void *ptr);
int ClientThread(void *ptr);

int main(int argc, char *argv[])
{
    SDL_Thread *worker, *db, *client;
    int workerAwakeValue, dbAwakeValue, clientAwakeValue;

    printf("\nSimple SDL_CreateThread test:");

    worker = SDL_CreateThread(WorkerThread, "WorkerTestThread", (void *)NULL);

    if (NULL == worker)
	{
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }
	else
	{
        SDL_WaitThread(worker, &workerAwakeValue);
        printf("\nWorker thread returned value: %d", workerAwakeValue);
		SDL_Delay(250);
    }

	db = SDL_CreateThread(DbThread, "DBTestThread", (void *)NULL);

    if (NULL == db)
	{
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }
	else
	{
        SDL_WaitThread(db, &dbAwakeValue);
        printf("\nDatabase thread returned value: %d", dbAwakeValue);
		SDL_Delay(250);
    }

	client = SDL_CreateThread(ClientThread, "ClientTestThread", (void *)NULL);

    if (NULL == db)
	{
        printf("\nSDL_CreateThread failed: %s\n", SDL_GetError());
    }
	else
	{
        SDL_WaitThread(db, &clientAwakeValue);
        printf("\nClient thread returned value: %d", clientAwakeValue);
		SDL_Delay(250);
    }

	SDL_Delay(2000);
	printf("\n\nPress enter to exit...\n");
	getchar();
	SDL_Quit();
    return 0;
}

// Very simple thread - counts 0 to 9 delaying 50ms between increments
int WorkerThread(void *ptr)
{
	BlockingQueue<TempCommands> commandsQ;

	TempCommands c1, c2, c3, c4, c5;

	// Temporary Placeholder Examples
	c1.SetDescription("Command-Startup");		// Server Startup
	c2.SetDescription("Command-Initializing");	// InitializeSettings After Startup
	c3.SetDescription("Command-Running");		// Server Running
	c4.SetDescription("Command-Storing");		// StoreSettings Before Shutdown
	c5.SetDescription("Command-Shutdown");		// Server Shutdown
	
	commandsQ.push(c1);
	commandsQ.push(c2);
	commandsQ.push(c3);
	commandsQ.push(c4);
	commandsQ.push(c5);

	int threadCnt = commandsQ.size();

	//while (alive)
	while (true)
	{
		if (commandsQ.empty())
		{
			// Sleep

			printf("\n\nEnding Worker Thead...(Temporary Behaviour Only)\n");

			SDL_Delay(1000);
			break;
		}
		else
		{
			printf("\nCommand Running (%i): ", commandsQ.front());
			commandsQ.front().PrintDescription();
			commandsQ.pop();

			// Execute popped command

			SDL_Delay(750);
		}
	}

	return threadCnt;
}

int DbThread(void *ptr)
{


    return 0;
}

int ClientThread(void *ptr)
{


    return 0;
}
//*/

/*
// Server
#include <SDL.h>
#include <SDL_net.h>
#include <iostream>
#include <string>

int main(int argc, char* argcs[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip, nullptr, 32000);

	TCPsocket serverSocket = SDLNet_TCP_Open(&ip);
	TCPsocket clientSocket;

	std::cout << "Waiting for a connection..." << std::endl;
	while (true) {
		clientSocket = SDLNet_TCP_Accept(serverSocket);

		if (clientSocket) {
			char* data = new char[100];

			SDLNet_TCP_Send(clientSocket, data, 100);
			SDLNet_TCP_Close(clientSocket);
			break;
		}
	}

	std::cout << "Finished." << std::endl;
	std::cin.get();
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}

//*/

