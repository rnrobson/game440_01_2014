#ifndef COMMAND_CREATE_NEW_GAME_H
#define COMMAND_CREATE_NEW_GAME_H

#include "ServerCommand.h"
#include "GameManager.h"

class Command_CreateNewGame : public ServerCommand
{
private:
	uint gameID;
public:
	//Command_CreateNewGame(void* _data)
	Command_CreateNewGame(uint _gameID)
	{
		gameID = _gameID;
	}
	~Command_CreateNewGame(){}

	void Execute()
	{
		if (gameID<1)
		{
			/*	cout << "invalid game id";
			cout << endl; */
		}
		else{
			//uint gameID = *(unsigned int*)data;

			GameModel* game = new GameModel(gameID);
			if (GameManager::games.size() < GameManager::MAX_GAMES)
			{
				GameManager::games.push_back(game);
				cout << "Game created with ID: " << gameID << endl;
			}
			else
			{
				/*	cout << "Max Games Reached - Unable to create new game";
				cout << endl;*/
			}
		}
	}
};

#endif