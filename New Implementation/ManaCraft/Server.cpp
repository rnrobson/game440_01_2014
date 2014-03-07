#include "Server.h"


/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
std::vector<GameModel*> Server::games;
const int Server::MAX_GAMES = 10;

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
	unsigned int id = 2;
	/*Command_CreateNewGame* command = new Command_CreateNewGame(&id);
	command->Execute();*/
	/*id++;
	command = new Command_CreateNewGame(&id);
	command->Execute();*/

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
	//games.reserve(MAX_GAMES);
	//
	////creating a new hardcoded game
	//GameModel* game1 = new GameModel();
	//games.push_back(game1);

	//for each (GameModel* game in games)
	//{
	//	std::cout << game->towers[0]->name;
	//}
	////commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();


}
