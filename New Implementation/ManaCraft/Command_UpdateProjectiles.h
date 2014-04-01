#ifndef COMMAND_UPDATE_PROJECTILES_H
#define COMMAND_UPDATE_PROJECTILES_H

#include "PacketFactory.h"
#include "GameManager.h"
#include "Packet.h"

class Command_UpdateProjectiles : public CommandPacket
{
private:
	uint gameID;
	Packet nullPacket;
public:
	Command_UpdateProjectiles(uint _gameID) : CommandPacket(&nullPacket)
	{
		gameID = _gameID;
	}
	~Command_UpdateProjectiles(){}

	void Execute()
	{
		cout << "Updating projectiles in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{

				gameFound = true;
				GameManager::games[i]->UpdateProjectiles();
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