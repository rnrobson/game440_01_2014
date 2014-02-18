#include "ServerIncludes.h"
#include "ServerCommand.h"

ServerCommand::ServerCommand()
{
	std::cout << "\nServer Command Created";
}

ServerCommand::~ServerCommand()
{
	//std::cout << "\nServer Command Destroyed";
}

void ServerCommand::Execute()
{
	printf("\nServerCommand: Executed command: %i", command);

}