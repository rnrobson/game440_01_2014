#ifndef COMMAND_SC_PAUSE_GAME_H
#define COMMAND_SC_PAUSE_GAME_H

#include "PacketFactory.h"
#include "GameManager.h"
#include "Packet.h"
#include "Server.h"


class Command_CS_PauseGame : public CommandPacket
{
private:
	uint gameID;
	Packet nullPacket;
public:
	Command_CS_PauseGame(uint _gameID) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
	}
	~Command_CS_PauseGame(){}

	void Execute()
	{
		cout << "Updating towers in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{
				gameFound = true;
				//toggle paused
				GameManager::games[i]->paused = !GameManager::games[i]->paused;

				//create a SC_command to broadcast the pause to cleints in that game
				//checked clientliaison ... there is no functionality yet to send anything to a client
				//Server::AddWork(scPauseGameCommand);
				break;
			}
		}
		if (!gameFound)
		{
			cout << "GameID " << gameID << " not found";
		}


	}

};

#endif