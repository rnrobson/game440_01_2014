#include "Server.h"
#include "ClientLiaison.h"
#include "ServerIncludes.h"
#include "ServerCommandTester.h"

/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{
	
	Init();
	

}

void Server::Run()
{
	/*workQueue.push(ServerCommand((void *)1, CS_PLACE_TOWER));
	ServerCommand *runningCommand = &workQueue.pop();
	void *data = runningCommand->getData();
	runningCommand->Execute(data);*/


	ServerCommandTester* tester = new ServerCommandTester(50);
	std::cout << "\nrunning TestTripleAFloatCommand...";
	tester->TestTripleAFloatCommand();
	std::cout << "\nrunning TestIntFloatProductCommand...";
	tester->TestIntFloatProductCommand();
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
	//setting limit of running games
	games.reserve(MAX_GAMES);
	
	//creating a new hardcoded game
	GameModel* game1 = new GameModel();
	games.push_back(game1);

	//commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();


}
