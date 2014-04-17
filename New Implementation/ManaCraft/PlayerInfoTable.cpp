//#include "PlayerInfoTable.h"
//
//PlayerInfoTable::PlayerInfoTable()
//{
//	playerGameTable = std::map<std::string, std::pair<ServerLobby*, GameModel*>>();
//}
//
//PlayerInfoTable::~PlayerInfoTable()
//{
//
//}
//
//PlayerInfoTable* PlayerInfoTable::playerInfoTable = 0;
//
//PlayerInfoTable* PlayerInfoTable::GetInstance()
//{
//	if (playerInfoTable == 0)
//	{
//		playerInfoTable = new PlayerInfoTable();
//	}
//
//	return playerInfoTable;
//}
//
//std::map<std::string, std::pair<ServerLobby*, GameModel*>> PlayerInfoTable::GetTable()
//{
//	return playerGameTable;
//}
//
//static GameModel *GetGame(std::string username)
//{
//	GameModel *game;
//
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				game = (*iter).second.second; // return the active Game the player with this name is in.
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				game = (*iter).second.second; // return the active Game the player with this name is in.
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				game = (*iter).second.second; // return the active Game the player with this name is in.
//				break;
//			}
//		}
//	}
//
//	return game;
//}
//
//static Player *GetPlayer(std::string username)
//{
//	Player *player;
//
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				player = (*bench); // return the player object associated with this username
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				player = (*team1); // return the player object associated with this username
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				player = (*team2); // return the player object associated with this username
//				break;
//			}
//		}
//	}
//
//	return player;
//}
///// <COME BACK TO FINISH> Not sure how the ServerLobby works with GameModel
///*
//static ServerLobby *GetLobby(std::string username)
//{
//	ServerLobby *lobby;
//
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				//lobby = NOT SURE HOW LOBBY WORKS WITH GAMEMODEL ATM
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				//lobby = NOT SURE HOW LOBBY WORKS WITH GAMEMODEL ATM
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				//lobby = NOT SURE HOW LOBBY WORKS WITH GAMEMODEL ATM
//				break;
//			}
//		}
//	}
//
//	return lobby;
//}*/
//
//static Teams *GetTeams(std::string username)
//{
//	Teams *teams;
//
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				teams = (*iter).second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				teams = (*iter).second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				teams = (*iter).second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//	}
//
//	return teams;
//}
///// <COME BACK TO FINISH>
///*
//static std::vector<Player*> *GetTeamPlayerIsOn(std::string username)
//{
//	std::vector<Player*> team;
//
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				//team = (*iter).second.second->teams->Bench();
//				//team = (*iter)->second.second->teams->Bench();
//				//team = iter->second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				//team = iter->second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				//team = iter->second.second->teams; // return the teams associated with the game this username is in
//				break;
//			}
//		}
//	}
//
//	return team;
//}*/
///// <COME BACK TO FINISH> Same as above problem
///*
//static std::list<ServerPlayer> GetPlayersInGame(GameModel game)
//{
//	if (playerInfoTable == 0)
//	{
//		return 0;
//	}
//
//	return players; 
//}*/
//
//static void Insert(std::string username, ServerLobby *lobby)
//{
//	PlayerInfoTable::GetInstance()->GetTable().insert(std::pair<std::string, ServerLobby*>(username, lobby));
//}
//
//static void Modify(std::string username, GameModel *game)
//{
//	std::map<std::string, std::pair<ServerLobby*, GameModel*>>::iterator iter;
//	std::vector<Player*>::iterator bench;
//	std::vector<Player*>::iterator team1;
//	std::vector<Player*>::iterator team2;
//
//	for (iter = PlayerInfoTable::GetInstance()->GetTable().begin();
//		 iter != PlayerInfoTable::GetInstance()->GetTable().end();
//		 iter++)
//	{
//		for (bench = iter->second.second->teams->Bench.begin();
//			 bench != iter->second.second->teams->Bench.end();
//			 bench++)
//		{
//			if (username.c_str() == (*bench)->username.c_str())
//			{
//				(*iter).second.first = 0; // Set ServerLobby of map value to null
//				(*iter).second.second = game; // Set the game to the new initialized parameter value
//				break;
//			}
//		}
//
//		for (team1 = iter->second.second->teams->Team1.begin();
//			 team1 != iter->second.second->teams->Team1.end();
//			 team1++)
//		{
//			if (username.c_str() == (*team1)->username.c_str())
//			{
//				(*iter).second.first = 0; // Set ServerLobby of map value to null
//				(*iter).second.second = game; // Set the game to the new initialized parameter value
//				break;
//			}
//		}
//
//		for (team2 = iter->second.second->teams->Team2.begin();
//			 team2 != iter->second.second->teams->Team2.end();
//			 team2++)
//		{
//			if (username.c_str() == (*team2)->username.c_str())
//			{
//				(*iter).second.first = 0; // Set ServerLobby of map value to null
//				(*iter).second.second = game; // Set the game to the new initialized parameter value
//				break;
//			}
//		}
//	}
//}
//
//static void Erase(std::string username)
//{
//	PlayerInfoTable::GetInstance()->GetTable().erase(username);
//}