#pragma once

#include <vector>

#include "ServerPlayer.h"

using namespace std;

class Teams
{
public:
	int PlayerCount;
	int MaxPlayers;
	vector<ServerPlayer*> Bench;
	vector<ServerPlayer*> Team1;
	vector<ServerPlayer*> Team2;

	Teams(int teamSize);
	Teams();
	~Teams(void);

	void EnterNewPlayer(ServerPlayer *player);
	void PlayerChangeTeam(ServerPlayer *player, vector<ServerPlayer*> *toTeam);
	void KickPlayer(ServerPlayer *player);
private:
	bool FindAndRemove(ServerPlayer *player);
};
