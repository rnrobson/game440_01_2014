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
/*
	ServerTester* tester = new ServerTester(50);
	std::cout << "\nrunning Test_Command_TripleAFloat...";
	tester->Test_Command_TripleAFloat();
	std::cout << "\nrunning Test_Command_IntFloatProduct...";
	tester->Test_Command_IntFloatProduct();
	std::cout << "\nRunning all tests...";
	tester->RunAllTests();*/
	unsigned int id = 1;
	ServerCommand* command = new Command_CreateNewGame(&id);
	workQueue.push(command);
	cout << "New Game Command - game id: " << id;
	cout << endl;
	id++;
	command = new Command_CreateNewGame(&id);
	workQueue.push(command);
	cout << "New Game Command - game id: "<< id;
	cout << endl;

	workQueue.front()->Execute();
	workQueue.pop();
		
	cout << "Created new game - Number of games: " << GameManager::games.size();
	cout << endl;
	workQueue.front()->Execute();
	workQueue.pop();
	cout << "Created new game - Number of games: " << GameManager::games.size();
	cout << endl;
	

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

	//commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();
}
