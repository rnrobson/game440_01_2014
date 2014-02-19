#include "ServerIncludes.h"
#include "ServerCommand.h"

ServerCommand::ServerCommand()
{
	std::cout << "\nServer Command Created";
}

ServerCommand::~ServerCommand()
{
	//std::cout << "\nServer Command Destroyed";
}
void* ServerCommand::getData()
{
	return data;
}

void ServerCommand::Execute(void* _data)
{
	switch (command)
	{
	case CS_CLOSE_GAME:
		printf("\nDEBUG CS_CLOSE_GAME Exicuted with ID %i\n", command);
		CS_CloseGame(_data);
		break;
	case CS_LOGIN_PLAYER:
		printf("\nDEBUG CS_CLOSE_GAME Exicuted with ID %i\n", command);
		CS_LoginPlayer(_data);
		break;
	case CS_LOGOUT_PLAYER:
		printf("\nDEBUG CS_LOGOUT_PLAYER Exicuted with ID %i\n", command);
		CS_LogoutPlayer(_data);
		break;
	case CS_REFRESH_GAMES:
		printf("\nDEBUG CS_REFRESH_GAMES Exicuted with ID %i\n", command);
		CS_RefreshGames(_data);
		break;
	case CS_JOIN_GAME:
		printf("\nDEBUG CS_JOIN_GAME Exicuted with ID %i\n", command);
		CS_JoinGame(_data);
		break;
	case CS_CREATE_GAME:
		printf("\nDEBUG CS_CREATE_GAME Exicuted with ID %i\n", command);
		CS_CreateGame(_data);
		break;
	case CS_LEAVE_GAME:
		printf("\DEBUG CS_LEAVE_GAME Exicuted with ID %i\n", command);
		CS_LeaveGame(_data);
		break;
	case CS_DISBAND_GAME:
		printf("\DEBUG CS_DISBAND_GAME Exicuted with ID: %i\n", command);
		CS_DisbandGame(_data);
		break;
	case CS_JOIN_TEAM:
		printf("\nDEBUG CS_JOIN_TEAM Exicuted with ID: %i\n", command);
		CS_JoinTeam(_data);
		break;
	case CS_READY_STATUS:
		printf("\nDEBUG CS_READY_STATUS Exicuted with ID: %i\n", command);
		CS_ReadyStatus(_data);
		break;
	case CS_BENCH_PLAYER:
		printf("\nDEBUG CS_BENCH_PLAYER Exicuted with ID: %i\n", command);
		CS_BenchPlayer(_data);
		break;
	case CS_SET_GAMEPLAY_OPTIONS:
		printf("\nDEBUG CS_SET_GAMEPLAY_OPTIONS Exicuted with ID: %i\n", command);
		CS_SetGamePlayOptions(_data);
		break;
	case CS_SEND_MSG_PARTY:
		printf("\nDEBUG CS_SEND_MSG_PARTY Exicuted with ID: %i\n", command);
		CS_SendMsgParty(_data);
		break;
	case CS_SEND_MSG_TEAM:
		printf("\nDEBUG CS_SEND_MSG_TEAM Exicuted with ID: %i\n", command);
		CS_SendMsgTeam(_data);
		break;
	case CS_SEND_MSG_LOBBY:
		printf("\nDEBUG CS_SEND_MSG_LOBBY Exicuted with ID: %i\n", command);
		CS_SendMsgLobby(_data);
		break;
	case CS_SEND_WHISPER:
		printf("\nDEBUG CS_SEND_WHISPER Exicuted with ID: %i\n", command);
		CS_SendWhisper(_data);
		break;
	case CS_SEND_PARTY_MSG:
		printf("\nDEBUG CS_SEND_PARTY_MSG Exicuted with ID: %i\n", command);
		CS_SendMsgParty(_data);
		break;
	case CS_KICK_PLAYER:
		printf("\nDEBUG CS_KICK_PLAYER Exicuted with ID: %i\n", command);
		CS_KickPlayer(_data);
		break;
	case CS_PAUSE_GAME:
		printf("\nDEBUG CS_PAUSE_GAME Exicuted with ID: %i\n", command);
		CS_PauseGame(_data);
		break;
	case CS_END_GAME:
		printf("\nDEBUG CS_END_GAME Exicuted with ID: %i\n", command);
		CS_EndGame(_data);
		break;
	case CS_RESUME_GAME:
		printf("\nDEBUG CS_RESUME_GAME Exicuted with ID: %i\n", command);
		CS_ResumeGame(_data);
		break;
	case CS_QUIT_GAME:
		printf("\nDEBUG CS_QUIT_GAME Exicuted with ID: %i\n", command);
		CS_QuitGame(_data);
		break;
	case CS_PLACE_TOWER:
		printf("\nDEBUG CS_PLACE_TOWER Exicuted with ID: %i\n", command);
		CS_PlaceTower(_data);
		break;
	case CS_SUMMON_MINION:
		printf("\nDEBUG CS_SUMMON_MINION Exicuted with ID: %i\n", command);
		CS_SummonMinion(_data);
		break;
	case CS_RESEARCH_MINION:
		printf("\nDEBUG CS_RESEARCH_MINION Exicuted with ID: %i\n", command);
		CS_ResearchMinion(_data);
		break;
	case CS_RESEARCH_TOWER:
		printf("\nDEBUG CS_RESEARCH_TOWER Exicuted with ID: %i\n", command);
		CS_ResearchTower(_data);
		break;
	case SC_LOGIN_PLAYER:
		printf("\nDEBUG SC_LOGIN_PLAYER Exicuted with ID: %i\n", command);
		SC_LoginPlayer(_data);
		break;
	case SC_REFRESH_GAMES:
		printf("\nDEBUG SC_REFRESH_GAMES Exicuted with ID: %i\n", command);
		SC_RefreshGames(_data);
		break;
	case SC_JOIN_GAME:
		printf("\nDEBUG SC_JOIN_GAME Exicuted with ID: %i\n", command);
		SC_JoinGame(_data);
		break;
	case SC_CREATE_GAME:
		printf("\nDEBUG SC_CREATE_GAME Exicuted with ID: %i\n", command);
		SC_CreateGame(_data);
		break;
	case SC_DISBAND_GAME:
		printf("\nDEBUG SC_DISBAND_GAME Exicuted with ID: %i\n", command);
		SC_DisbandGame(_data);
		break;
	case SC_JOIN_TEAM:
		printf("\nDEBUG SC_JOIN_TEAM Exicuted with ID: %i\n", command);
		SC_JoinGame(_data);
		break;
	case SC_BENCH_PLAYER:
		printf("\nDEBUG SC_BENCH_PLAYER Exicuted with ID: %i\n", command);
		SC_BenchPlayer(_data);
		break;
	case SC_UPDATE_LOBBY:
		printf("\nDEBUG SC_UPDATE_LOBBY Exicuted with ID: %i\n", command);
		SC_UpdateLobby(_data);
		break;
	case SC_SEND_MESSAGE:
		printf("\nDEBUG SC_SEND_MESSAGE Exicuted with ID: %i\n", command);
		SC_SendMessage(_data);
		break;
	case SC_PAUSE_GAME:
		printf("\nDEBUG SC_PAUSE_GAME Exicuted with ID: %i\n", command);
		SC_PauseGame(_data);
		break;
	case SC_END_GAME:
		printf("\nDEBUG SC_END_GAME Exicuted with ID: %i\n", command);
		SC_EndGame(_data);
		break;
	case SC_RESUME_GAME:
		printf("\nDEBUG SC_RESUME_GAME Exicuted with ID: %i\n", command);
		SC_ResumeGame(_data);
		break;
	case SC_QUIT_GAME:
		printf("\nDEBUG SC_QUIT_GAME Exicuted with ID: %i\n", command);
		SC_QuitGame(_data);
		break;
	case SC_SUMMON_MINION:
		printf("\nDEBUG SC_SUMMON_MINION Exicuted with ID: %i\n", command);
		SC_SummonMinion(_data);
		break;
	case SC_PLACE_TOWER:
		printf("\nDEBUG SC_PLACE_TOWER Exicuted with ID: %i\n", command);
		SC_PlaceTower(_data);
		break;
	case SC_UPDATE_ECONOMY:
		printf("\nDEBUG SC_UPDATE_ECONOMY Exicuted with ID: %i\n", command);
		SC_UpdateEconomy(_data);
		break;
	case SC_UPDATE_BASE_HP:
		printf("\nDEBUG SC_UPDATE_BASE_HP Exicuted with ID: %i\n", command);
		SC_UpdateBaseHP(_data);
		break;
	case SC_ASSIGN_RESOURCE_NODE:
		printf("\nDEBUG SC_ASSIGN_RESOURCE_NODE Exicuted with ID: %i\n", command);
		SC_AssignResourceNode(_data);
		break;
	case SC_RESEARCH_MINION:
		printf("\nDEBUG SC_RESEARCH_MINION Exicuted with ID: %i\n", command);
		SC_ResearchMinion(_data);
		break;
	case SC_RESEARCH_TOWER:
		printf("\nDEBUG SC_RESEARCH_TOWER Exicuted with ID: %i\n", command);
		SC_ResearchTower(_data);
		break;
	case IS_PLACE_TOWER_BC:
		printf("\nDEBUG IS_PLACE_TOWER_BC Exicuted with ID: %i\n", command);
		IS_PlaceTowerBC(_data);
		break;
	case IS_ADJUST_ZOI:
		printf("\nDEBUG IS_ADJUST_ZOI Exicuted with ID: %i\n", command);
		IS_AdjustZoi(_data);
		break;
	case IS_SUMMON_MINION_BC:
		printf("\nDEBUG IS_SUMMON_MINION_BC Exicuted with ID: %i\n", command);
		IS_SummonMinionBC(_data);
		break;
	case IS_UPDATE_MINION_LIST:
		printf("\nDEBUG IS_UPDATE_MINION_LIST Exicuted with ID: %i\n", command);
		IS_UpdateMinionList(_data);
		break;
	case IS_UPDATE_TOWERLISTS:
		printf("\nDEBUG IS_UPDATE_TOWERLISTS Exicuted with ID: %i\n", command);
		IS_UpdateTowerList(_data);
		break;
	case IS_UPDATE_PROJECTILES:
		printf("\nDEBUG IS_UPDATE_PROJECTILES Exicuted with ID: %i\n", command);
		IS_UpdateProjLists(_data);
		break;
	case IS_UPDATE_ECONOMY:
		printf("\nDEBUG IS_UPDATE_ECONOMY Exicuted with ID: %i\n", command);
		IS_UpdateEconomy(_data);
		break;
	default:
		break;
	}
}

void ServerCommand::CS_CloseGame(void* data){ printf("\nPut CS_CloseGame Code Here\n"); }
void ServerCommand::CS_LoginPlayer(void* data){ printf("\nPut CS_LoginPlayer Code Here\n"); }
void ServerCommand::CS_LogoutPlayer(void* data){ printf("\nPut CS_LogoutPlayer Code Here\n"); }
void ServerCommand::CS_RefreshGames(void* data){ printf("\nPut CS_RefreshGames Code Here\n"); }
void ServerCommand::CS_JoinGame(void* data){ printf("\nPut CS_JoinGame Code Here\n"); }
void ServerCommand::CS_CreateGame(void* data){ printf("\nPut CS_CreateGame Code Here\n"); }
void ServerCommand::CS_LeaveGame(void* data){ printf("\nPut CS_LeaveGame Code Here\n"); }
void ServerCommand::CS_DisbandGame(void* data){ printf("\nPut CS_DisbandGame Code Here\n"); }
void ServerCommand::CS_JoinTeam(void* data){ printf("\nPut CS_JoinTeam Code Here\n"); }
void ServerCommand::CS_ReadyStatus(void* data){ printf("\nPut CS_ReadyStatus Code Here\n"); }
void ServerCommand::CS_BenchPlayer(void* data){ printf("\nPut CS_BenchPlayer Code Here\n"); }
void ServerCommand::CS_SetGamePlayOptions(void* data){ printf("\nPut CS_SetGamePlayOptions Code Here\n"); }
void ServerCommand::CS_SendMsgParty(void* data){ printf("\nPut CS_SendMsgParty Code Here\n"); }
void ServerCommand::CS_SendMsgTeam(void* data){ printf("\nPut CS_SendMsgTeam Code Here\n"); }
void ServerCommand::CS_SendMsgLobby(void* data){ printf("\nPut CS_SendMsgLobby Code Here\n"); }
void ServerCommand::CS_SendWhisper(void* data){ printf("\nPut CS_SendWhisper Code Here\n"); }
void ServerCommand::CS_KickPlayer(void* data){ printf("\nPut CS_KickPlayer Code Here\n"); }
void ServerCommand::CS_PauseGame(void* data){ printf("\nPut CS_PauseGame Code Here\n"); }
void ServerCommand::CS_EndGame(void* data){ printf("\nPut CS_EndGame Code Here\n"); }
void ServerCommand::CS_ResumeGame(void* data){ printf("\nPut CS_ResumeGame Code Here\n"); }
void ServerCommand::CS_QuitGame(void* data){ printf("\nPut CS_QuitGame Code Here\n"); }
void ServerCommand::CS_PlaceTower(void* data){ printf("\nPut CS_PlaceTower Code Here\n"); }
void ServerCommand::CS_SummonMinion(void* data){ printf("\nPut CS_SummonMinion Code Here\n"); }
void ServerCommand::CS_ResearchMinion(void* data){ printf("\nPut CS_ResearchMinion Code Here\n"); }
void ServerCommand::CS_ResearchTower(void* data){ printf("\nPut CS_ResearchTower Code Here\n"); }

void ServerCommand::SC_LoginPlayer(void* data){ printf("\nPut SC_LoginPlayer Code Here\n"); }
void ServerCommand::SC_RefreshGames(void* data){ printf("\nPut SC_RefreshGames Code Here\n"); }
void ServerCommand::SC_JoinGame(void* data){ printf("\nPut SC_JoinGame Code Here\n"); }
void ServerCommand::SC_CreateGame(void* data){ printf("\nPut SC_CreateGame Code Here\n"); }
void ServerCommand::SC_DisbandGame(void* data){ printf("\nPut SC_DisbandGame Code Here\n"); }
void ServerCommand::SC_JoinTeam(void* data){ printf("\nPut SC_JoinTeam Code Here\n"); }
void ServerCommand::SC_BenchPlayer(void* data){ printf("\nPut SC_BenchPlayer Code Here\n"); }
void ServerCommand::SC_UpdateLobby(void* _data){ printf("\nPut SC_UpdateLobby Code Here\n"); }
void ServerCommand::SC_SendMessage(void* data){ printf("\nPut SC_SendMessage Code Here\n"); }
void ServerCommand::SC_PauseGame(void* data){ printf("\nPut SC_PauseGame Code Here\n"); }
void ServerCommand::SC_EndGame(void* data){ printf("\nPut SC_EndGame Code Here\n"); }
void ServerCommand::SC_ResumeGame(void* data){ printf("\nPut SC_ResumeGame Code Here\n"); }
void ServerCommand::SC_QuitGame(void* data){ printf("\nPut SC_QuitGame Code Here\n"); }
void ServerCommand::SC_PlaceTower(void* data){ printf("\nPut SC_PlaceTower Code Here\n"); }
void ServerCommand::SC_SummonMinion(void* data){ printf("\nPut SC_SummonMinion Code Here\n"); }
void ServerCommand::SC_UpdateEconomy(void* data){ printf("\nPut SC_UpdateEconomy Code Here\n"); }
void ServerCommand::SC_UpdateBaseHP(void* data){ printf("\nPut SC_UpdateBaseHP Code Here\n"); }
void ServerCommand::SC_AssignResourceNode(void* data){ printf("\nPut SC_AssignResourceNode Code Here\n"); }
void ServerCommand::SC_ResearchMinion(void* data){ printf("\nPut SC_ResearchMinion Code Here\n"); }
void ServerCommand::SC_ResearchTower(void* data){ printf("\nPut SC_ResearchTower Code Here\n"); }

void ServerCommand::IS_PlaceTowerBC(void* data){ printf("\nPut IS_PlaceTowerBC Code Here\n"); }
void ServerCommand::IS_AdjustZoi(void* data){ printf("\nPut IS_AdjustZoi Code Here\n"); }
void ServerCommand::IS_SummonMinionBC(void* data){ printf("\nPut IS_SummonMinionBC Code Here\n"); }
void ServerCommand::IS_UpdateMinionList(void* data){ printf("\nPut IS_UpdateMinionList Code Here\n"); }
void ServerCommand::IS_UpdateTowerList(void* data){ printf("\nPut IS_UpdateTowerList Code Here\n"); }
void ServerCommand::IS_UpdateProjLists(void* data){ printf("\nPut IS_UpdateProjLists Code Here\n"); }
void ServerCommand::IS_UpdateEconomy(void* data){ printf("\nPut IS_UpdateEconomy Code Here\n"); }
