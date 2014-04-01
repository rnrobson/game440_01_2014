#ifndef COMMAND_UPDATE_ECONOMY_H
#define COMMAND_UPDATE_ECONOMY_H

#include "PacketFactory.h"
#include "GameManager.h"
#include "Packet.h"

class Command_UpdateEconomy : public CommandPacket
{
private:
	uint gameID;
	Uint32 dt;
	Packet nullPacket;
public:
	Command_UpdateEconomy(uint _gameID, Uint32 _dt) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
		dt = _dt;
	}
	~Command_UpdateEconomy(){}

	void Execute()
	{
		cout << "Updating economy in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{

				gameFound = true;
				GameManager::games[i]->UpdateEconomy(dt);
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