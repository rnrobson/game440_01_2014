
#include "LocalDB.h"
#include <algorithm>
#include "Minion.h"
#include "GameManager.h"

std::vector<GameModel*> LocalDB::games;

LocalDB::LocalDB()
{
	cout << "[LocalDB]: Created...\n";
	
	if (InitConnection())
	{
		cout << "[LocalDB]: Connected to DB...\n";
	}
	LoadTables();
}

LocalDB::~LocalDB()
{
	cout << "[LocalDB]: Deconstructing LocalDB...\n";
	for (size_t i = 0; i < games.size(); i++)
	{
		if (games[i])
		{
			SaveGame(i);
			UnloadGame(i);
		}
	}

	if (CloseConnection())
	{
		cout << "[LocalDB]: Disconnected from DB...\n";
	}
}

void LocalDB::LoadTables()
{
	//dbConnection->loadMinionsTable();
}

bool LocalDB::InitConnection()
{
	dbConnection->connectToDatabase();
	return dbConnection->isConnected();
}

bool LocalDB::CloseConnection()
{
	if (dbConnection->isConnected())
	{
		dbConnection->disconnectFromDatabase();
	}
	return !dbConnection->isConnected();
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
	return NULL; //request the game from the DB and creates a game and adds it to the games vector and load it
}

ManaCraft::Database::DatabaseAPI* LocalDB::getDbConnection()
{
	return dbConnection;
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
	GameModel* gm = GameManager::FindGame(_gameID);
	//persist game locally
	games.push_back(gm);

	//save game to DB
	gm->SaveGame();

	// delete game from running games
	gm->DeleteGame();


	return true;
}
