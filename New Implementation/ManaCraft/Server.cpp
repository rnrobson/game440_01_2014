#include "Server.h"
#include "PacketFactory.h"

BlockingQueue<CommandPacket*> InitQueue()
{
	BlockingQueue<CommandPacket*> temp;
	return temp;
}
BlockingQueue<CommandPacket*> Server::workQueue(InitQueue());

Server::Server()
{
	Init();
	
}
void Server::Run()
{
	running = true;

	//uncomment this to run tests for the server commands before game loop starts
	
	//ServerTester* tester = new ServerTester(50);

	//tester->Test_Command_TripleAFloat();
	//tester->Test_Command_IntFloatProduct();
	//tester->Test_Command_CreateNewGame(); 
	//tester->Test_Command_UpdateMinions();

	//tester->Test_ServerLobby(workCrew);

	/*std::cout << "\nRunning all tests...";
	tester->RunAllTests();*/

	
	bool dontUpdate; // There might be too many ticks per ms
	int timeSnapshot = -1; // Temp var for comparing ms for above issue
	
	//spoofing commands coming in from the client to the workQueue
	Uint32 testTimeSnapShot = -1;
	bool dontTest;

	while (running)
	{
		//pop a command off workqueu if any are present
		if (!workQueue.empty())
		{
			workQueue.front()->Execute();
			workQueue.pop();
		}

		//go into update loop

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
			CommandPacket* testCMD = new Command_TripleAFloat(&x);
			Server::AddWork(testCMD);

		}
		testTimeSnapShot = elapsedTime;
	}

	

	getchar();
}

Server::~Server()
{

}

void Server::Init()
{
	running = true;
	elapsedTime = 0;

	gameManager = new GameManager();

	CommandPacket* newGameCMD = new Command_CreateNewGame(1);
	Server::AddWork(newGameCMD);

	localDB = new LocalDB();

}

void Server::Update() {
	
	CommandPacket* updateMinsCMD = new Command_UpdateMinions(1);
	Server::AddWork(updateMinsCMD);

}
void Server::AddWork(CommandPacket* command)
{
	Server::workQueue.push(command);
}

void Server::Shutdown()
{
	running = false;
	while (!workQueue.empty())
	{
		workQueue.pop();
	}
	delete gameManager;
	delete localDB;
}