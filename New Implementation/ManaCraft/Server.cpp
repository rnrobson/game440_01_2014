#include "Server.h"
#include "ClientLiaison.h"
#include "ServerIncludes.h"


/// <summary>[Server]
/// <para>The Server's Constructor</para>
/// </summary>
Server::Server()
{


	workQueue.push(ServerCommand((void *)1, CS_CLOSE_GAME));
	ServerCommand *runningCommand = &workQueue.pop();
	void *data = runningCommand->getData();
	runningCommand->Execute(data);

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
