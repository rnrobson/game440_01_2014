#pragma once

#include <vector>
#include "ServerPlayer.h"
#include "DatabaseAPI.h"

using namespace std;

class Teams
{
public:
	unsigned int team1ID, team2ID;
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

	static Teams* LoadTeamsByIDs(int _team1ID, int _team2ID);

private:
	bool FindAndRemove(ServerPlayer *player);
};
