#ifndef COMMAND_CREATE_NEW_GAME_H
#define COMMAND_CREATE_NEW_GAME_H

#include "ServerCommand.h"
#include "GameManager.h"

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
		GameModel* game = new GameModel(*(unsigned int*)data);
		if (GameManager::games.size() <  GameManager::MAX_GAMES)
		{
			GameManager::games.push_back(game);
		}
		else
		{
			cout << "Max Games Reached - Unable to create new game";
		}
	}
};

#endif