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

		if (gameID<1)
		{
			/*cout << "invalid game id";
			cout << endl;*/
		}
		else
		{
			//for each (GameModel* game in GameManager::games)
			vector<GameModel*> games = GameManager::games;
			for (size_t i = 0; i < games.size(); i++)
			{
				if (games[i]->id == gameID)
				{

					gameFound = true;
					UpdateMinions(games[i]);
					break;
				}
			}
			if (!gameFound)
			{
				cout << "GameID " << gameID << " not found";
			}
			games.clear();
		}


	}
	void UpdateMinions(GameModel* game)
	{
		vector<Minion*> minions = game->minions;
		for (size_t i = 0; i < minions.size(); i++)
		{
			//update pos
			minions[i]->xPos += minions[i]->speed;
			minions[i]->yPos += minions[i]->speed;
			//make sure collider is updated with position
			minions[i]->collisionBox->x = (int)round(minions[i]->xPos) - minions[i]->colWidth / 2;
			minions[i]->collisionBox->y = (int)round(minions[i]->yPos) - minions[i]->colHeight / 2;

			if (minions[i]->health <= 0)
			{
				//remove MpS bonus from player who had spawned it
				minions.erase(minions.begin() + i);
				continue;
			}

			//get reference to player to find out which base this minion should do damage to
			//assuming this is a light minion - will do damage to dark base
			if (SDL_IntersectRect(game->darkBase->collisionBox, minions[i]->collisionBox, new SDL_Rect()))
			{
				game->darkBase->TakeDamage(minions[i]->damage);
				//remove MpS bonus from player who had spawned it
				minions.erase(minions.begin() + i);
				continue;
			}
		}
		game->minions = minions;
		minions.clear();
	}

};

#endif