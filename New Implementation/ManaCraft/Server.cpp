#include "Server.h"
#include "ClientLiaison.h"
#include "ServerIncludes.h"


/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{

	ServerCommand *sc = new ServerCommand((void *)1, SC_UPDATE_ECONOMY);
	workQueue.push(*sc);
	ServerCommand *runningCommand = &workQueue.pop();
	runningCommand->Execute();

	Init();

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
	ClientLiaison::Run();
}
