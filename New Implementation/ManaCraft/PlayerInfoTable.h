//#ifndef PLAYERINFOTABLE_H
//#define PLAYERINFOTABLE_H
//
//#include <map>
//#include <list>
//#include <vector>
//
//#include "GameModel.h"
//#include "ServerPlayer.h"
//#include "ServerLobby.h"
//#include "Teams.h"
//
//class PlayerInfoTable
//{
//	private:
//		PlayerInfoTable();
//		~PlayerInfoTable();
//
//		static PlayerInfoTable *playerInfoTable;
//
//		//std::map<std::string, GameModel*> playerGameTable;
//		std::map<std::string, std::pair<ServerLobby*, GameModel*>> playerGameTable;
//
//	public:
//		std::map<std::string, std::pair<ServerLobby*, GameModel*>> GetTable();
//
//		static PlayerInfoTable *GetInstance();
//		static GameModel *GetGame(std::string username);
//		static Player *GetPlayer(std::string username);
//		static ServerLobby *GetLobby(std::string username);
//		static Teams *GetTeam(std::string username);
//		static std::vector<Player*> *GetTeamPlayerIsOn(std::string username);
//		static std::list<Player> *GetPlayersInGame(GameModel game);
//		static void Insert(std::string username, ServerLobby *lobby); // Used when lobby is created
//		static void Modify(std::string username, GameModel *game); // Used when GameModel is initialized and lobby left
//		static void Erase(std::string username);
//};
//
//#endif