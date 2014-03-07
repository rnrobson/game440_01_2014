#ifndef COMMAND_CREATE_NEW_GAME_H
#define COMMAND_CREATE_NEW_GAME_H

//#include <iostream>

#include "ServerCommand.h"
#include "Server.h"
//#include "GameModel.h"


//#include "ServerCommandIncludes.h"

class Command_CreateNewGame : public ServerCommand
{
public:

	Command_CreateNewGame(void* _data)
	{
		data = _data;

	}
	~Command_CreateNewGame(){}

	void Execute()
	{
		//GameModel* game = new GameModel(*(unsigned int*)data);
		////GameModel* game = new GameModel(2);
		//if (Server::games.size() < 10)// Server::MAX_GAMES)
		//{
		//	Server::games.push_back(game);
		//}
		//else
		//{
		//	cout << "Max Games Reached - Unable to create new game";
		//}
		//cout << Server::games.size();
	}

};

#endif