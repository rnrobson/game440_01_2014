#ifndef COMMAND_INITIALIZE_NEW_GAME_H
#define COMMAND_INITIALIZE_NEW_GAME_H

#include "PacketFactory.h"
#include "GameManager.h"

class Command_InitializeNewGame : public CommandPacket
{
private:
	uint gameID;
	Teams *teams;
	ServerPlayer *host;
	Packet nullPacket;
public:
	Command_InitializeNewGame(uint _gameID, Teams *_teams, ServerPlayer *_host) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
		teams = _teams;
		host = _host;
	}
	~Command_InitializeNewGame(){}

	void Execute()
	{
		GameModel *gameModel;
		gameModel = GameManager::FindGame(gameID);
		gameModel->teams = teams;
		gameModel->host = host;
	}
};

#endif