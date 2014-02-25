#include "Server.h"
#include "ClientLiaison.h"
#include "ServerIncludes.h"


/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{
	
	
	/*int commandData = 1;
	ServerCommand *tempCommand = new TestCommand(&commandData);*/

	Int_Float_Product_Params* params = new Int_Float_Product_Params(3.0f, 6);
	ServerCommand *tempCommand1 = new Int_Float_Product_Command(params);
	workQueue.push(tempCommand1);

	float commandData = 2.0f;
	ServerCommand *tempCommand2 = new TripleAFloatCommand(&commandData);
	workQueue.push(tempCommand2);

	std::cout << std::endl;

	workQueue.front()->Execute();
	workQueue.pop();

	workQueue.front()->Execute();
	workQueue.pop();

	
	//Init();
	
	getchar();


	/*workQueue.push(ServerCommand((void *)1, CS_PLACE_TOWER));
	ServerCommand *runningCommand = &workQueue.pop();
	void *data = runningCommand->getData();
	runningCommand->Execute(data);

	Init();

	getchar();*/
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
	ClientLiaison::Run();
}
