#ifndef COMMAND_CS_RESUME_GAME_H
#define COMMAND_CS_RESUME_GAME_H

#include "PacketFactory.h"
#include "GameManager.h"
#include "Packet.h"

class Command_SC_ResumeGame : public CommandPacket
{
private:
	uint gameID;
	Packet nullPacket;
public:
	Command_SC_ResumeGame(uint _gameID) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
	}
	~Command_SC_ResumeGame(){}

	void Execute()
	{
		cout << "Updating towers in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{
				gameFound = true;

				GameManager::games[i]->paused = !GameManager::games[i]->paused;
				//this is a redundant command. pausegame can be used to toggle pause
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