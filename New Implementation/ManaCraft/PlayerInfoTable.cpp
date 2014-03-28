#include "PlayerInfoTable.h"

PlayerInfoTable::PlayerInfoTable()
{
	playerGameTable = std::map<std::string, GameModel*>();
}

PlayerInfoTable::~PlayerInfoTable()
{

}

PlayerInfoTable* PlayerInfoTable::playerInfoTable = 0;

PlayerInfoTable* PlayerInfoTable::GetInstance()
{
	if (playerInfoTable == 0)
	{
		playerInfoTable = new PlayerInfoTable();
	}

	return playerInfoTable;
}


static GameModel *GetGame(std::string username)
{
	if (playerInfoTable == 0)
	{
		return 0;
	}

	GameModel *game;

	std::map<std::string, GameModel*>::iterator iter;
	std::vector<ServerPlayer*>::iterator iter2;
	std::vector<ServerPlayer*>::iterator iter3;
	std::vector<ServerPlayer*>::iterator iter4;

	for (iter = PlayerInfoTable::GetInstance()->playerGameTable.begin();
		 iter != PlayerInfoTable::GetInstance()->playerGameTable.end();
		 iter++)
	{
		for (iter2 = iter->second()->teams->Bench.begin();
			 iter2 != iter->second()->teams->Bench.end();
			 iter2++)
		{
			if (username.c_str() == iter->userrname.c_str())
			{
				game = iter->second(); // return the active Game the player with this name is in.
				break;
			}
		}

		for (iter3 = iter->second()->teams->Team1.begin();
			 iter3 != iter->second()->teams->Team1.end();
			 iter3++)
		{
			if (username.c_str() == iter->userrname.c_str())
			{
				game = iter->second(); // return the active Game the player with this name is in.
				break;
			}
		}

		for (iter4 = iter->second()->teams->Team2.begin();
			 iter4 != iter->second()->teams->Team2.end();
			 iter4++)
		{
			if (username.c_str() == iter->userrname.c_str())
			{
				game = iter->second(); // return the active Game the player with this name is in.
				break;
			}
		}
	}

	return game;
}
/*
static ServerPlayer *GetPlayer(std::string username)
{
	if (playerInfoTable == 0)
	{
		return 0;
	}

	return player;
}*/
/*
static ServerLobby *GetLobby(std::string username);
{
	if (playerInfoTable == 0)
	{
		return 0;
	}

	return lobby;
}*/
/*
static Teams *GetTeams(std::string username);
{
	if (playerInfoTable == 0)
	{
		return 0;
	}

	return teams;
}*/
/*
static std::list<ServerPlayer> GetPlayersInGame(GameModel game)
{
	if (playerInfoTable == 0)
	{
		return 0;
	}

	return players; 
}*/
/*
static Insert(std::string username, GameModel game)
{
	
}*/
/*
static Erase(std::string username)
{

}
*/