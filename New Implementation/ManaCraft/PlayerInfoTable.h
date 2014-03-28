#ifndef PLAYERINFOTABLE_H
#define PLAYERINFOTABLE_H

#include <map>
#include <list>
#include <vector>

#include "GameModel.h"
#include "ServerPlayer.h"
#include "ServerLobby.h"
#include "Teams.h"

/// <Untested and Unfinished> Will come back to later.

class PlayerInfoTable
{
	private:
		PlayerInfoTable();
		~PlayerInfoTable();

		static PlayerInfoTable *playerInfoTable;

		std::map<std::string, GameModel*> playerGameTable;

	public:
		static PlayerInfoTable *GetInstance();
		static GameModel *GetGame(std::string username);
		static ServerPlayer *GetPlayer(std::string username);
		static ServerLobby *GetLobby(std::string username);
		static Teams *GetTeams(std::string username);
		static std::list<ServerPlayer> GetPlayersInGame(GameModel game);
		static Insert(std::string username, GameModel game);
		static Erase(std::string username);
};

#endif