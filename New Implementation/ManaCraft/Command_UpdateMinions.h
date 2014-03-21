#ifndef COMMAND_UPDATE_MINIONS_H
#define COMMAND_UPDATE_MINIONS_H

#include "ServerCommand.h"
#include "GameManager.h"

class Command_UpdateMinions : public ServerCommand
{
private:
	uint gameID;
public:
	//Command_UpdateMinions(void* _data)
	Command_UpdateMinions(uint _gameID)
	{
		gameID = _gameID;
	}
	~Command_UpdateMinions(){}

	void Execute()
	{
		cout << "Updating minions in game ID: " << gameID << endl;
		bool gameFound = false;

		for (size_t i = 0; i < GameManager::games.size(); i++)
		{
			if (GameManager::games[i]->id == gameID)
			{

				gameFound = true;
				GameManager::games[i]->UpdateMinions();
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