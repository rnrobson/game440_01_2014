#include "Server.h"

/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{
	Init();
}
/// <summary>[Run]
/// <para>This method starts running the server</para>
/// </summary>
void Server::Run()
{
	running = true;

	//ServerTester* tester = new ServerTester(50);

	//tester->Test_Command_TripleAFloat();
	//tester->Test_Command_IntFloatProduct();
	//tester->Test_Command_CreateNewGame(); 
	//tester->Test_Command_UpdateMinions();

	bool dontUpdate; // There might be too many ticks per ms
	int timeSnapshot = -1; // Temp var for comparing ms for above issue
	
	//spoofing commands coming in from the client to the workQueue
	Uint32 testTimeSnapShot = -1;
	bool dontTest;

	while (true)
	{
		// Grab us the time since SDL init
		elapsedTime = SDL_GetTicks();

		// If the snapshot of the last cycle (in ms) is the same as the current,
		// suspend update (we want 16 per, not more)
		if (timeSnapshot == elapsedTime) {
			dontUpdate = true;
		}
		else {
			dontUpdate = false;
		}

		// If we're allowed to update, do so.
		if (!dontUpdate) {
			if (elapsedTime % deltaTime == 0)
			{
				printf("Update\n");
				Update();
			}
		}

		/* NEED A BREAK CONDITION TO MAKE THIS WHILE TRUE NOT RETARDED */

		// Take a snapshot of the current ms
		timeSnapshot = elapsedTime;


		//spoofing commands coming in from the client to the workQueue every 2 secs
		Uint32 timeToSimulateCommand = 2000;
		if (testTimeSnapShot == elapsedTime)
			dontTest = true;
		else
			dontTest = false;

		if (!dontTest && elapsedTime % timeToSimulateCommand == 0)
		{
			float x = rand() % 99;
			ServerCommand* testCMD = new Command_TripleAFloat(&x);
			workCrew->addWork(testCMD);

		}
		testTimeSnapShot = elapsedTime;
	}

	/*std::cout << "\nRunning all tests...";
	tester->RunAllTests();
*/
	getchar();
}

/// <summary>[~Server]
/// <para>The Server's Destructor</para>
/// </summary>
Server::~Server()
{

}

/// <summary>[Init]
/// <para>This methind initializes the server. Imports the settings via XML and loads the Client Liaison, woirker and DB Liaison</para>
/// </summary>
void Server::Init()
{
	running = false;
	elapsedTime = 0;

	gameManager = new GameManager();
	workCrew = new ThreadPool(numWorkers);

	ServerCommand* newGameCMD = new Command_CreateNewGame(1);
	//workQueue.push(cmd);
	workCrew->addWork(newGameCMD);
	//commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();
}

void Server::Update() {
	
	ServerCommand* updateMinsCMD = new Command_UpdateMinions(1);
	workCrew->addWork(updateMinsCMD);

}