#include "Server.h"

/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{
	Init();
	Run();
}
/// <summary>[Run]
/// <para>This method starts running the server</para>
/// </summary>
void Server::Run()
{
	ServerTester* tester = new ServerTester(50);

	//tester->Test_Command_TripleAFloat();
	//tester->Test_Command_IntFloatProduct();
	//tester->Test_Command_CreateNewGame(); 
	//tester->Test_Command_UpdateMinions();

	bool dontUpdate; // There might be too many ticks per ms
	int timeSnapshot = -1; // Temp var for comparing ms for above issue
	Uint32 elapsedTime = 0;
	Uint32 deltaTime = 16;
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
	}

	std::cout << "\nRunning all tests...";
	tester->RunAllTests();

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
	gameManager = new GameManager();

	int myGameID = 1;
	gameManager = new GameManager();
	ServerCommand* cmd = new Command_CreateNewGame(&myGameID);
	cmd->Execute();
	//commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();
}

void Server::Update() {
	int myGameID = 1;
	ServerCommand* cmd = new Command_UpdateMinions(&myGameID);
	workQueue.push(cmd);

	if (!workQueue.empty()) {
		workQueue.front()->Execute();
		workQueue.pop();
	}
}