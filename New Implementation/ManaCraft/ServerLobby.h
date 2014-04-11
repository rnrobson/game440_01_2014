#pragma once

#include <vector>

#include "Teams.h"
#include "GameModel.h"
#include "Command_CreateNewGame.h"
#include "Command_InitializeNewGame.h"
#include "ThreadPool.h"
#include "GameManager.h"

using namespace std;

class ServerLobby
{
public:
	Player *host;
	Teams teams;
	vector<Player*> readyPlayers;
	ThreadPool *WorkCrew;

	ServerLobby(ThreadPool *workCrew, Player *lobbyHost, int teamSize);
	ServerLobby();
	~ServerLobby();
	
	void StartGame();
	void CloseLobby();
	void ReadyPlayer(Player *player);
	void UnReadyPlayer(Player *player);
	void PlayerMessage(Player *player, string message);

	void EnterNewPlayer(Player *player);
	void PlayerChangeTeam(Player *player, vector<Player*> *toTeam);
	void KickPlayer(Player *player);
};

