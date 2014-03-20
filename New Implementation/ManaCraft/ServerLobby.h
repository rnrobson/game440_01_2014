#pragma once

#include <vector>

#include "Teams.h"
#include "GameModel.h"
#include "Command_CreateNewGame.h"
#include "ThreadPool.h"
#include "GameManager.h"

using namespace std;

class ServerLobby
{
public:
	ServerPlayer *host;
	Teams teams;
	vector<ServerPlayer*> readyPlayers;
	ThreadPool *WorkCrew;

	ServerLobby(ThreadPool *workCrew, ServerPlayer *lobbyHost, int teamSize);
	ServerLobby();
	~ServerLobby();
	
	void StartGame();
	void CloseLobby();
	void ReadyPlayer(ServerPlayer *player);
	void UnReadyPlayer(ServerPlayer *player);
	void PlayerMessage(ServerPlayer *player, string message);

	void EnterNewPlayer(ServerPlayer *player);
	void PlayerChangeTeam(ServerPlayer *player, vector<ServerPlayer*> *toTeam);
	void KickPlayer(ServerPlayer *player);
};

