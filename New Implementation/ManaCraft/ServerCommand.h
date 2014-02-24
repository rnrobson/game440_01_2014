#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


#include "ServerIncludes.h"
#include <iostream>

enum ServerProtocol : int
{
	CS_CLOSE_GAME,
	CS_LOGIN_PLAYER,
	CS_LOGOUT_PLAYER,
	CS_REFRESH_GAMES,
	CS_JOIN_GAME,
	CS_CREATE_GAME,
	CS_LEAVE_GAME,
	CS_DISBAND_GAME,
	CS_JOIN_TEAM,
	CS_READY_STATUS,
	CS_BENCH_PLAYER,
	CS_SET_GAMEPLAY_OPTIONS,
	CS_SEND_MSG_TEAM,
	CS_SEND_MSG_BROADCAST,
	CS_SEND_WHISPER,
	CS_KICK_PLAYER,
	CS_PAUSE_GAME,
	CS_END_GAME,
	CS_RESUME_GAME,
	CS_QUIT_GAME,
	CS_PLACE_TOWER,
	CS_SUMMON_MINION,
	CS_RESEARCH_MINION,
	CS_RESEARCH_TOWER,

	SC_LOGIN_PLAYER,
	SC_REFRESH_GAMES,
	SC_JOIN_GAME,
	SC_CREATE_GAME,
	SC_DISBAND_GAME,
	SC_JOIN_TEAM,
	SC_BENCH_PLAYER,
	SC_UPDATE_LOBBY,
	SC_SEND_MESSAGE,
	SC_PAUSE_GAME,
	SC_END_GAME,
	SC_RESUME_GAME,
	SC_QUIT_GAME,
	SC_SUMMON_MINION,
	SC_PLACE_TOWER,
	SC_UPDATE_ECONOMY,
	SC_UPDATE_BASE_HP,
	SC_ASSIGN_RESOURCE_NODE,
	SC_RESEARCH_MINION,
	SC_RESEARCH_TOWER,

	IS_PLACE_TOWER_BC,
	IS_ADJUST_ZOI,
	IS_SUMMON_MINION_BC,
	IS_UPDATE_MINION_LIST,
	IS_UPDATE_TOWERLISTS,
	IS_UPDATE_PROJECTILES,
	IS_UPDATE_ECONOMY
};


class ServerCommand
{
private: 
	void *data;
	ServerProtocol command;

	void CS_CloseGame(void* data);
	void CS_LoginPlayer(void* data);
	void CS_LogoutPlayer(void* data);
	void CS_RefreshGames(void* data);
	void CS_JoinGame(void* data);
	void CS_CreateGame(void* data);
	void CS_LeaveGame(void* data);
	void CS_DisbandGame(void* data);
	void CS_JoinTeam(void* data);
	void CS_ReadyStatus(void* data);
	void CS_BenchPlayer(void* data);
	void CS_SetGamePlayOptions(void* data);
	void CS_SendMsgTeam(void* data);
	void CS_SendMsgBroadcast(void* data);
	void CS_SendWhisper(void* data);
	void CS_KickPlayer(void* data);
	void CS_PauseGame(void* data);
	void CS_EndGame(void* data);
	void CS_ResumeGame(void* data);
	void CS_QuitGame(void* data);
	void CS_PlaceTower(void* data);
	void CS_SummonMinion(void* data);
	void CS_ResearchMinion(void* data);
	void CS_ResearchTower(void* data);
	
	void SC_LoginPlayer(void* data);
	void SC_RefreshGames(void* data);
	void SC_JoinGame(void* data);
	void SC_CreateGame(void* data);
	void SC_DisbandGame(void* data);
	void SC_JoinTeam(void* data);
	void SC_BenchPlayer(void* data);
	void SC_UpdateLobby(void* _data);
	void SC_SendMessage(void* data);
	void SC_PauseGame(void* data);
	void SC_EndGame(void* data);
	void SC_ResumeGame(void* data);
	void SC_QuitGame(void* data);
	void SC_PlaceTower(void* data);
	void SC_SummonMinion(void* data);
	void SC_UpdateEconomy(void* data);
	void SC_UpdateBaseHP(void* data);
	void SC_AssignResourceNode(void* data);
	void SC_ResearchMinion(void* data);
	void SC_ResearchTower(void* data);

	void IS_PlaceTowerBC(void* data);
	void IS_AdjustZoi(void* data);
	void IS_SummonMinionBC(void* data);
	void IS_UpdateMinionList(void* data);
	void IS_UpdateTowerList(void* data);
	void IS_UpdateProjLists(void* data);
	void IS_UpdateEconomy(void* data);



public:
	ServerCommand();
	ServerCommand(void* _data, ServerProtocol _command) : data(_data), command(_command) { printf("\nServerCommand Initialized as type: %i", _command); };
	~ServerCommand();
	void* getData();

	void Execute(void* _data);
};
#endif