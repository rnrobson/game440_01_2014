#ifndef COMMAND_UPDATE_TOWERS_H
#define COMMAND_UPDATE_TOWERS_H

#include "PacketFactory.h"
#include "GameManager.h"
#include "Packet.h"

class Command_UpdateTowers : public CommandPacket
{
private:
	uint gameID;
	Uint32 dt;
	Packet nullPacket;
public:
	Command_UpdateTowers(uint _gameID, Uint32 _dt) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
		dt = _dt;
	}
	~Command_UpdateTowers(){}

	void Execute()
	{
		cout << "Updating towers in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{
				gameFound = true;
				GameManager::games[i]->UpdateTowers(dt);
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