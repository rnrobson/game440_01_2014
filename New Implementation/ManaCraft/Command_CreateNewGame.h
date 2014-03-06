#ifndef COMMAND_CREATE_NEW_GAME_H
#define COMMAND_CREATE_NEW_GAME_H

//#include <iostream>
//#include "ServerCommand.h"
#include "Server.h"
//#include "GameModel.h"


//#include "ServerCommandIncludes.h"


//struct CreateNewGame
//{
//public:
//	float x;
//	int y;
//	float result;
//	IntFloatProductParams(float _x, int _y)
//	{
//		x = _x;
//		y = _y;
//		result = 0;
//	}
//	~IntFloatProductParams(){}
//};
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
		////GameModel* game = new GameModel(*(unsigned int*)data);
		//GameModel* game = new GameModel(2);
		////if (Server::games.size() < 10)// Server::MAX_GAMES)
		//{
		//	Server::games.push_back(game);
		//}
		///*else
		//{
		//	cout << "Max Games Reached - Unable to create new game";
		//}*/
	}

};

#endif