#ifndef LOCAL_DB_H
#define LOCAL_DB_H

#include <vector>
#include "GameModel.h"
#include "DatabaseAPI.h"

class LocalDB 
{

private:
	bool InitConnection();
	bool CloseConnection();
	static std::vector<GameModel*> games;
	ManaCraft::Database::DatabaseAPI *dbConnection;

public:
	static GameModel* LoadGame(uint _gameID);
	bool UnloadGame(uint _gameID);
	bool SaveGame(uint _gameID);

	LocalDB();
	~LocalDB();
};

#endif
