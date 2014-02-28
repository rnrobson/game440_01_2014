#include "Server.h"
#include "ClientLiaison.h"
#include "ServerIncludes.h"
#include "ServerCommandTester.h"

/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{
	
	
	/*int commandData = 1;
	ServerCommand *tempCommand = new TestCommand(&commandData);*/
/*
	IntFloatProductParams* params = new IntFloatProductParams(3.0f, 6);
	ServerCommand *tempCommand1 = new IntFloatProductCommand(params);
	workQueue.push(tempCommand1);

	float commandData = 2.0f;
	ServerCommand *tempCommand2 = new TripleAFloatCommand(&commandData);
	workQueue.push(tempCommand2);

	std::cout << std::endl;

	workQueue.front()->Execute();
	workQueue.pop();

	workQueue.front()->Execute();
	workQueue.pop();*/

	
	//Init();

	ServerCommandTester* tester = new ServerCommandTester(250);
	std::cout << "\nrunning TestTripleAFloatCommand...";
	tester->TestTripleAFloatCommand();
	std::cout << "\nrunning TestIntFloatProductCommand...";
	tester->TestIntFloatProductCommand();
	std::cout << "\nRunning all tests...";
	tester->RunAllTests();
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
