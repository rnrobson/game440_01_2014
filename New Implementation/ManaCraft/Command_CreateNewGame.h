#ifndef COMMAND_CREATE_NEW_GAME_H
#define COMMAND_CREATE_NEW_GAME_H

#include "PacketFactory.h"
#include "GameManager.h"

class Command_CreateNewGame : public CommandPacket
{
private:
	uint gameID;
	Packet nullPacket;
public:
	Command_CreateNewGame(uint _gameID) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
	}
	~Command_CreateNewGame(){}

	void Execute()
	{
		GameModel* game = new GameModel(gameID);
		if (GameManager::games.size() < GameManager::MAX_GAMES)
		{
			GameManager::games.push_back(game);
			cout << "Game created with ID: " << gameID << endl;
		}
		else
		{
			cout << "Max Games Reached - Unable to create new game";
			cout << endl;
		}
	}
};

#endif