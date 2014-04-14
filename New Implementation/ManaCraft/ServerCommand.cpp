#include "ServerIncludes.h"
#include "ServerCommand.h"
ServerCommand::ServerCommand()
{
	//std::cout << "\nserver Command Initialized";
}

ServerCommand::~ServerCommand()
{
	//std::cout << "\nServer Command Destroyed";
}

void ServerCommand::Execute()
{
	//std::cout << "\nServerCommand: Execute!";
}

//#include "ServerIncludes.h"
//#include "ServerCommand.h"
//
//ServerCommand::ServerCommand()
//{
//	std::cout << "\nServer Command Created";
//}
//
//ServerCommand::~ServerCommand()
//{
//	//std::cout << "\nServer Command Destroyed";
//}
//void* ServerCommand::getData()
//{
//	return data;
//}
//
//void ServerCommand::Execute(void* _data)
//{
//	switch (command)
//	{
//	case CS_CLOSE_GAME:
//		printf("\nDEBUG CS_CLOSE_GAME Executed with ID %i\n", command);
//		CS_CloseGame(_data);
//		break;
//	case CS_LOGIN_PLAYER:
//		printf("\nDEBUG CS_CLOSE_GAME Executed with ID %i\n", command);
//		CS_LoginPlayer(_data);
//		break;
//	case CS_LOGOUT_PLAYER:
//		printf("\nDEBUG CS_LOGOUT_PLAYER Executed with ID %i\n", command);
//		CS_LogoutPlayer(_data);
//		break;
//	case CS_REFRESH_GAMES:
//		printf("\nDEBUG CS_REFRESH_GAMES Executed with ID %i\n", command);
//		CS_RefreshGames(_data);
//		break;
//	case CS_JOIN_GAME:
//		printf("\nDEBUG CS_JOIN_GAME Executed with ID %i\n", command);
//		CS_JoinGame(_data);
//		break;
//	case CS_CREATE_GAME:
//		printf("\nDEBUG CS_CREATE_GAME Executed with ID %i\n", command);
//		CS_CreateGame(_data);
//		break;
//	case CS_LEAVE_GAME:
//		printf("\DEBUG CS_LEAVE_GAME Executed with ID %i\n", command);
//		CS_LeaveGame(_data);
//		break;
//	case CS_DISBAND_GAME:
//		printf("\DEBUG CS_DISBAND_GAME Executed with ID: %i\n", command);
//		CS_DisbandGame(_data);
//		break;
//	case CS_JOIN_TEAM:
//		printf("\nDEBUG CS_JOIN_TEAM Executed with ID: %i\n", command);
//		CS_JoinTeam(_data);
//		break;
//	case CS_READY_STATUS:
//		printf("\nDEBUG CS_READY_STATUS Executed with ID: %i\n", command);
//		CS_ReadyStatus(_data);
//		break;
//	case CS_BENCH_PLAYER:
//		printf("\nDEBUG CS_BENCH_PLAYER Executed with ID: %i\n", command);
//		CS_BenchPlayer(_data);
//		break;
//	case CS_SET_GAMEPLAY_OPTIONS:
//		printf("\nDEBUG CS_SET_GAMEPLAY_OPTIONS Executed with ID: %i\n", command);
//		CS_SetGamePlayOptions(_data);
//		break;
//	case CS_SEND_MSG_TEAM:
//		printf("\nDEBUG CS_SEND_MSG_TEAM Executed with ID: %i\n", command);
//		CS_SendMsgTeam(_data);
//		break;
//	case CS_SEND_MSG_BROADCAST:
//		printf("\nDEBUG CS_SEND_MSG_BROADCAST Executed with ID: %i\n", command);
//		CS_SendMsgBroadcast(_data);
//		break;
//	case CS_SEND_WHISPER:
//		printf("\nDEBUG CS_SEND_WHISPER Executed with ID: %i\n", command);
//		CS_SendWhisper(_data);
//		break;
//	case CS_KICK_PLAYER:
//		printf("\nDEBUG CS_KICK_PLAYER Executed with ID: %i\n", command);
//		CS_KickPlayer(_data);
//		break;
//	case CS_PAUSE_GAME:
//		printf("\nDEBUG CS_PAUSE_GAME Executed with ID: %i\n", command);
//		CS_PauseGame(_data);
//		break;
//	case CS_END_GAME:
//		printf("\nDEBUG CS_END_GAME Executed with ID: %i\n", command);
//		CS_EndGame(_data);
//		break;
//	case CS_RESUME_GAME:
//		printf("\nDEBUG CS_RESUME_GAME Executed with ID: %i\n", command);
//		CS_ResumeGame(_data);
//		break;
//	case CS_QUIT_GAME:
//		printf("\nDEBUG CS_QUIT_GAME Executed with ID: %i\n", command);
//		CS_QuitGame(_data);
//		break;
//	case CS_PLACE_TOWER:
//		printf("\nDEBUG CS_PLACE_TOWER Executed with ID: %i\n", command);
//		CS_PlaceTower(_data);
//		break;
//	case CS_SUMMON_MINION:
//		printf("\nDEBUG CS_SUMMON_MINION Executed with ID: %i\n", command);
//		CS_SummonMinion(_data);
//		break;
//	case CS_RESEARCH_MINION:
//		printf("\nDEBUG CS_RESEARCH_MINION Executed with ID: %i\n", command);
//		CS_ResearchMinion(_data);
//		break;
//	case CS_RESEARCH_TOWER:
//		printf("\nDEBUG CS_RESEARCH_TOWER Executed with ID: %i\n", command);
//		CS_ResearchTower(_data);
//		break;
//	case SC_LOGIN_PLAYER:
//		printf("\nDEBUG SC_LOGIN_PLAYER Executed with ID: %i\n", command);
//		SC_LoginPlayer(_data);
//		break;
//	case SC_REFRESH_GAMES:
//		printf("\nDEBUG SC_REFRESH_GAMES Executed with ID: %i\n", command);
//		SC_RefreshGames(_data);
//		break;
//	case SC_JOIN_GAME:
//		printf("\nDEBUG SC_JOIN_GAME Executed with ID: %i\n", command);
//		SC_JoinGame(_data);
//		break;
//	case SC_CREATE_GAME:
//		printf("\nDEBUG SC_CREATE_GAME Executed with ID: %i\n", command);
//		SC_CreateGame(_data);
//		break;
//	case SC_DISBAND_GAME:
//		printf("\nDEBUG SC_DISBAND_GAME Executed with ID: %i\n", command);
//		SC_DisbandGame(_data);
//		break;
//	case SC_JOIN_TEAM:
//		printf("\nDEBUG SC_JOIN_TEAM Executed with ID: %i\n", command);
//		SC_JoinGame(_data);
//		break;
//	case SC_BENCH_PLAYER:
//		printf("\nDEBUG SC_BENCH_PLAYER Executed with ID: %i\n", command);
//		SC_BenchPlayer(_data);
//		break;
//	case SC_UPDATE_LOBBY:
//		printf("\nDEBUG SC_UPDATE_LOBBY Executed with ID: %i\n", command);
//		SC_UpdateLobby(_data);
//		break;
//	case SC_SEND_MESSAGE:
//		printf("\nDEBUG SC_SEND_MESSAGE Executed with ID: %i\n", command);
//		SC_SendMessage(_data);
//		break;
//	case SC_PAUSE_GAME:
//		printf("\nDEBUG SC_PAUSE_GAME Executed with ID: %i\n", command);
//		SC_PauseGame(_data);
//		break;
//	case SC_END_GAME:
//		printf("\nDEBUG SC_END_GAME Executed with ID: %i\n", command);
//		SC_EndGame(_data);
//		break;
//	case SC_RESUME_GAME:
//		printf("\nDEBUG SC_RESUME_GAME Executed with ID: %i\n", command);
//		SC_ResumeGame(_data);
//		break;
//	case SC_QUIT_GAME:
//		printf("\nDEBUG SC_QUIT_GAME Executed with ID: %i\n", command);
//		SC_QuitGame(_data);
//		break;
//	case SC_SUMMON_MINION:
//		printf("\nDEBUG SC_SUMMON_MINION Executed with ID: %i\n", command);
//		SC_SummonMinion(_data);
//		break;
//	case SC_PLACE_TOWER:
//		printf("\nDEBUG SC_PLACE_TOWER Executed with ID: %i\n", command);
//		SC_PlaceTower(_data);
//		break;
//	case SC_UPDATE_ECONOMY:
//		printf("\nDEBUG SC_UPDATE_ECONOMY Executed with ID: %i\n", command);
//		SC_UpdateEconomy(_data);
//		break;
//	case SC_UPDATE_BASE_HP:
//		printf("\nDEBUG SC_UPDATE_BASE_HP Executed with ID: %i\n", command);
//		SC_UpdateBaseHP(_data);
//		break;
//	case SC_ASSIGN_RESOURCE_NODE:
//		printf("\nDEBUG SC_ASSIGN_RESOURCE_NODE Executed with ID: %i\n", command);
//		SC_AssignResourceNode(_data);
//		break;
//	case SC_RESEARCH_MINION:
//		printf("\nDEBUG SC_RESEARCH_MINION Executed with ID: %i\n", command);
//		SC_ResearchMinion(_data);
//		break;
//	case SC_RESEARCH_TOWER:
//		printf("\nDEBUG SC_RESEARCH_TOWER Executed with ID: %i\n", command);
//		SC_ResearchTower(_data);
//		break;
//	case IS_PLACE_TOWER_BC:
//		printf("\nDEBUG IS_PLACE_TOWER_BC Executed with ID: %i\n", command);
//		IS_PlaceTowerBC(_data);
//		break;
//	case IS_ADJUST_ZOI:
//		printf("\nDEBUG IS_ADJUST_ZOI Executed with ID: %i\n", command);
//		IS_AdjustZoi(_data);
//		break;
//	case IS_SUMMON_MINION_BC:
//		printf("\nDEBUG IS_SUMMON_MINION_BC Executed with ID: %i\n", command);
//		IS_SummonMinionBC(_data);
//		break;
//	case IS_UPDATE_MINION_LIST:
//		printf("\nDEBUG IS_UPDATE_MINION_LIST Executed with ID: %i\n", command);
//		IS_UpdateMinionList(_data);
//		break;
//	case IS_UPDATE_TOWERLISTS:
//		printf("\nDEBUG IS_UPDATE_TOWERLISTS Executed with ID: %i\n", command);
//		IS_UpdateTowerList(_data);
//		break;
//	case IS_UPDATE_PROJECTILES:
//		printf("\nDEBUG IS_UPDATE_PROJECTILES Executed with ID: %i\n", command);
//		IS_UpdateProjLists(_data);
//		break;
//	case IS_UPDATE_ECONOMY:
//		printf("\nDEBUG IS_UPDATE_ECONOMY Executed with ID: %i\n", command);
//		IS_UpdateEconomy(_data);
//		break;
//	default:
//		break;
//	}
//}
//
/*
void ServerCommand::CS_CloseGame(void* data)
{ 
	printf("\nPut CS_CloseGame Code Here\n"); 
	//args: string playerName
	string *playerName = data;
	//find player from collection of online players
	string currentPlayer = gamePlayerList.front;
	if(currentPlayer == playerName)
	{
		//remove reference of player from current game			
		playerName.Remove;
		//return player to main menu

		}
	}
	else
	{
		currentPlayer = gamePlayerList.Next;	
	}
}

void ServerCommand::CS_LoginPlayer(void* data)
{ 
	printf("\nPut CS_LoginPlayer Code Here\n"); 
	//args: string playerName
	string *playerName = data;

	//add player to collection of online players
	playerList.Push(playerName);
}

void ServerCommand::CS_LogoutPlayer(void* data)
{ 
	printf("\nPut CS_LogoutPlayer Code Here\n"); 
	//args: string playerName
		string *playerName = data;
	//find player from collection of online players
	string currentPlayer = serverPlayerList.front;
	if(currentPlayer == playerName)
	{
		//remove reference of player from current game			
		playerName.Remove;
		//return player to main menu

		}
	}
	else
	{
		currentPlayer = serverPlayerList.Next;	
	}
}
	//return player to main menu (with the login option)
}

void ServerCommand::CS_RefreshGames(void* data)
{ 
	printf("\nPut CS_RefreshGames Code Here\n"); 
	//args: string playerName, uint lobbyID
	string *playerName = data;
	GameData lobbyID = data;
	//go through list of all avaialble games connected to the server
	for (int i = 0; i <lobbyID.Length; i++)
	(
		//display them to current player's client
		printf (lobbyID[i] "/n");
	}
}
void ServerCommand::CS_JoinGame(void* data)
{ 
	printf("\nPut CS_JoinGame Code Here\n"); 
	//args: string playerName, uint gameID
	string *playerName;
	GameData gameID;
	//if this is a saved game
	if (gameID.save = true)
	{
		//	create a lobby with the game model from the saved game
		CS_createLobby(gameID.Model);
	//	check if the players associated with this game are online
		stack<bool> Status;
		Status.push (gameID.playerID)
		while(!Status.empty())
		{
		//		if so, send invites to them to join this game
		if (Status)
			invite(gameID.playerID);
		//		else, leave the spots open and open them to public
		else
			gameRoom.OpenSpots = true;
		}
	
	//if not a saved game, 
	else
	//	check if the game is full
	//		if not,
	//			add player to the game
		if (!gameRoom.OpenSpots)
		GameID.AddPlayer (playerID)

}
void ServerCommand::CS_CreateGame(void* data)
{ 
	printf("\nPut CS_CreateGame Code Here\n"); 
	//args: string playerName
	
	//create a new lobby and add it to the collection of lobbies on the server
	//add the player to the list of players in that lobby
	//flag player as host
}
void ServerCommand::CS_LeaveGame(void* data)
{ 
	printf("\nPut CS_LeaveGame Code Here\n"); 
	//args: string playerName, uint lobbyID
	//remove player from collection of players in the lobbyID
	//if that was the last player, remove the lobby from the collection of lobbies on the server
	//return player to main menu
}
void ServerCommand::CS_DisbandGame(void* data)
{
	printf("\nPut CS_DisbandGame Code Here\n"); 
	//args: uint lobby ID
	//return all players in the lobby to main menu
	
	//remove the lobby from the collection of lobbies on the server
}
*/
//void ServerCommand::CS_JoinTeam(void* data)
//{ 
//	printf("\nPut CS_JoinTeam Code Here\n"); 
//	//args: string playerName, uint lobbyID, uint teamID
//	//check if teamID has room for the player
//	//if yes:
//		//remove player from bench
//		//add player to team list
//		//return true
//	//if no:
//		//return false;
//}
//void ServerCommand::CS_ReadyStatus(void* data)
//{ 
//	printf("\nPut CS_ReadyStatus Code Here\n"); 
//	//args: string playerName
//	//toggle player's readyStatus bool
//}
//void ServerCommand::CS_BenchPlayer(void* data)
//{ 
//	printf("\nPut CS_BenchPlayer Code Here\n"); 
//	//args: string playerName
//	//find the lobby that player is in
//	//if the player is not already in the bench list: 
//		//remove player from a team list if he/she is in one
//		//add player to bench list
//}
//void ServerCommand::CS_SetGamePlayOptions(void* data)
//{ 
//	printf("\nPut CS_SetGamePlayOptions Code Here\n"); 
//	//args: uint gameID, ????? options
//	//go through game options model and set variables accordingly
//}
//void ServerCommand::CS_SendMsgTeam(void* data)
//{
//	printf("\nPut CS_SendMsgTeam Code Here\n");
//	//args: string senderName, string message
//	//if player is in a lobby:
//	//find all players in player's team in the lobby
//	//else if player is in a game, 
//	//find all players in the player's team in the game
//	//send the message to all those players
//}
//void ServerCommand::CS_SendMsgBroadcast(void* data)
//{
//	printf("\nPut CS_SendMsgBroadcast Code Here\n");
//	//args: string senderName, string message
//	//if player is in a lobby:
//		//find all players in player's lobby
//	//else if player is in a game, 
//		//find all players in the player's game
//	//send the message to all those players
//}
//void ServerCommand::CS_SendWhisper(void* data)
//{ 
//	printf("\nPut CS_SendWhisper Code Here\n"); 
//	//args: string senderName, string recipientName, string message
//	//find the recipient from collection of online players
//	//if found
//		//send message to recipient
//	//else
//		//display a message to player indicating that the recipient was not found
//}
//void ServerCommand::CS_KickPlayer(void* data)
//{ 
//	printf("\nPut CS_KickPlayer Code Here\n"); 
//	//args: string playerName
//	//find which game the player is in
//	//remove player from list of players in that game
//	//remove player back to game viewer screen
//	//notify other players involved in the game
//}
//void ServerCommand::CS_PauseGame(void* data)
//{ 
//	printf("\nPut CS_PauseGame Code Here\n"); 
//	//args: string playerName
//	//check for another pause request from the same gameID but from a different player
//	//if a 2nd one is received within X seconds
//		//pause the game
//}
//void ServerCommand::CS_EndGame(void* data)
//{ 
//	printf("\nPut CS_EndGame Code Here\n"); 
//	//args: string playerName
//	//make sure player is host
//		//save all game info to db
//		//remove all players to game viewer/main menu
//		//remove gameID from list of running games
//}
//void ServerCommand::CS_ResumeGame(void* data)
//{ 
//	printf("\nPut CS_ResumeGame Code Here\n"); 
//	//args: string playerName
//	//check to make sure player is host
//		//resume gameID
//}
//void ServerCommand::CS_QuitGame(void* data)
//{ 
//	printf("\nPut CS_QuitGame Code Here\n"); 
//	//args: string playerName
//	//remove player from game
//	//notify other players
//}
//void ServerCommand::CS_PlaceTower(void* data)
//{ 
//	printf("\nPut CS_PlaceTower Code Here\n"); 
//	//args: string playerName, uint towerID, uint gridspace
//	//check if tower has been researched for the player
//	//check if player has enough mana to build it
//	//check if grid is a buildable tile
//	//check if anything else is on that gridspace already
//	//check if gridspace is in player's team's zone of influence
//	//if the above is yes
//		//deduct cost from mana
//		//add towerID to gridspace
//		//add tower to tower list in the game representation
//		//check if gridspaces in ZoI of tower are already marked as ZoI for the team
//			//if not, mark as ZoI for team
//		//return true
//	//else return false
//}
//void ServerCommand::CS_SummonMinion(void* data)
//{ 
//	printf("\nPut CS_SummonMinion Code Here\n"); 
//	//args: string playerName, uint minionID
//	//check if minion has been researched for the player
//	//check if player has enough mana to summon the minion
//	//if yes:
//		//deduct cost from mana
//		//increase MpS (mana per second) as per minions MpS value
//		//spawn minion at player's team's portals
//		//add minion to minion list in the game representation
//		//update game representation
//		//return true
//	//else return false
//}
//void ServerCommand::CS_ResearchMinion(void* data)
//{ 
//	printf("\nPut CS_ResearchMinion Code Here\n"); 
//	//args: string playerName, uint minionID
//	//check if player has enough mana to research the minion
//	//if yes:
//		//flag minion as researched for player
//		//deduct cost from mana
//		//return true		
//	//else return false
//
//}
//void ServerCommand::CS_ResearchTower(void* data)
//{ 
//	printf("\nPut CS_ResearchTower Code Here\n"); 
//	//args: string playerName, uint towerID
//	//check if player has enough mana to research the tower
//	//if yes:
//		//flag tower as researched for player
//		//deduct cost from mana
//		//return true		
//	//else return false
//}
//
//void ServerCommand::SC_LoginPlayer(void* data){ printf("\nPut SC_LoginPlayer Code Here\n"); }
//void ServerCommand::SC_RefreshGames(void* data){ printf("\nPut SC_RefreshGames Code Here\n"); }
//void ServerCommand::SC_JoinGame(void* data){ printf("\nPut SC_JoinGame Code Here\n"); }
//void ServerCommand::SC_CreateGame(void* data){ printf("\nPut SC_CreateGame Code Here\n"); }
//void ServerCommand::SC_DisbandGame(void* data){ printf("\nPut SC_DisbandGame Code Here\n"); }
//void ServerCommand::SC_JoinTeam(void* data){ printf("\nPut SC_JoinTeam Code Here\n"); }
//void ServerCommand::SC_BenchPlayer(void* data){ printf("\nPut SC_BenchPlayer Code Here\n"); }
//void ServerCommand::SC_UpdateLobby(void* _data){ printf("\nPut SC_UpdateLobby Code Here\n"); }
//void ServerCommand::SC_SendMessage(void* data){ printf("\nPut SC_SendMessage Code Here\n"); }
//void ServerCommand::SC_PauseGame(void* data){ printf("\nPut SC_PauseGame Code Here\n"); }
//void ServerCommand::SC_EndGame(void* data){ printf("\nPut SC_EndGame Code Here\n"); }
//void ServerCommand::SC_ResumeGame(void* data){ printf("\nPut SC_ResumeGame Code Here\n"); }
//void ServerCommand::SC_QuitGame(void* data){ printf("\nPut SC_QuitGame Code Here\n"); }
//void ServerCommand::SC_PlaceTower(void* data){ printf("\nPut SC_PlaceTower Code Here\n"); }
//void ServerCommand::SC_SummonMinion(void* data){ printf("\nPut SC_SummonMinion Code Here\n"); }
//void ServerCommand::SC_UpdateEconomy(void* data){ printf("\nPut SC_UpdateEconomy Code Here\n"); }
//void ServerCommand::SC_UpdateBaseHP(void* data){ printf("\nPut SC_UpdateBaseHP Code Here\n"); }
//void ServerCommand::SC_AssignResourceNode(void* data){ printf("\nPut SC_AssignResourceNode Code Here\n"); }
//void ServerCommand::SC_ResearchMinion(void* data){ printf("\nPut SC_ResearchMinion Code Here\n"); }
//void ServerCommand::SC_ResearchTower(void* data){ printf("\nPut SC_ResearchTower Code Here\n"); }
//
//void ServerCommand::IS_PlaceTowerBC(void* data){ printf("\nPut IS_PlaceTowerBC Code Here\n"); }
//void ServerCommand::IS_AdjustZoi(void* data){ printf("\nPut IS_AdjustZoi Code Here\n"); }
//void ServerCommand::IS_SummonMinionBC(void* data){ printf("\nPut IS_SummonMinionBC Code Here\n"); }
//void ServerCommand::IS_UpdateMinionList(void* data)
//{ 
//	printf("\nPut IS_UpdateMinionList Code Here\n"); 
//	//args: uint gameID
//	//loop trough all minions in the minion list in the game ID
//	//check for HP
//		//if dead
//			//remove MpS bonus from player who had spawned it
//			//remove from minion list
//	//check if at enemy base
//		//if yes:
//			//do damage to enemy base
//			//kill minion
//	//update minion position (pathing)
//
//}
//void ServerCommand::IS_UpdateTowerList(void* data)
//{ 
//	printf("\nPut IS_UpdateTowerList Code Here\n"); 
//	//args: uint gameID
//	//loop through all towers in the tower list in the gameID
//		//loop through all minions in the game
//			//if any minion is in range
//				//fire at minion
//}
//void ServerCommand::IS_UpdateProjLists(void* data)
//{ 
//	printf("\nPut IS_UpdateProjLists Code Here\n"); 
//	//args: uint gameID
//	//loop through all projectiles in the list in the gameID
//		//loop through all minions
//			//check for collision
//				//if collided
//					//damage calculation (gets info from tower that owns projectile)
//					//despawn projectile
//		//if projectile reaches max range/timer
//			//despawn projectile
//}
//
//void ServerCommand::IS_UpdateEconomy(void* data)
//{ 
//	printf("\nPut IS_UpdateEconomy Code Here\n"); 
//	//args: uint gameID
//	//loop through all players in the gameID
//		//add MpS value to total mana
//}
