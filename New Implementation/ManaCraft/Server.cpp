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


	ServerTester* tester = new ServerTester(50);

	//tester->Test_Command_TripleAFloat();
	//tester->Test_Command_IntFloatProduct();
	//tester->Test_Command_CreateNewGame(); 
	//tester->Test_Command_UpdateMinions();

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

	//commenting out because it prevents anything else from displaying on the console
	//ClientLiaison::Run();
}
