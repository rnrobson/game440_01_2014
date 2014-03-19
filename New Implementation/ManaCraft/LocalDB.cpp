#include "LocalDB.h"
#include <algorithm>

std::vector<GameModel*> LocalDB::games;

LocalDB::LocalDB()
{
	InitConnection();
}

LocalDB::~LocalDB()
{
	CloseConnection();
	delete &dbConnection;
}

bool LocalDB::InitConnection()
{
	dbConnection->setConnectionParams("", "", "", "");
	dbConnection->connectToDatabase();
	return true;
}

bool LocalDB::CloseConnection()
{
	if (dbConnection->isConnected)
	{
		dbConnection->disconnectFromDatabase();
	}
	return true;
}

GameModel* LocalDB::LoadGame(uint _gameID)
{
	for (size_t i = 0; i < games.size(); i++)
	{
		if (games[i])
		{
			if (games[i]->id == _gameID)
			{
				return games[i];
			}
		}
	}
	return NULL; //request the game from the DB and creates a game, adds it to the games vector and load it
}

bool LocalDB::UnloadGame(uint _gameID)
{
	delete games[_gameID];
	games[_gameID] = NULL;
	sort(games.begin(), games.end(), GameModel::CompareGamesByID);
	return true;
}

bool LocalDB::SaveGame(uint _gameID)
{
	dbConnection->saveGame(); //this should take a gameModel and write the tables to the DB
	return true;
}
