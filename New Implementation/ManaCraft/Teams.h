#pragma once

#include <vector>
#include "DatabaseAPI.h"
#include "Player.h"

using namespace std;

class Teams
{
public:
	unsigned int team1ID, team2ID;
	int PlayerCount;
	int MaxPlayers;
	vector<Player*> Bench;
	vector<Player*> Team1;
	vector<Player*> Team2;

	Teams(int teamSize);
	Teams();
	~Teams(void);

	void EnterNewPlayer(Player *player);
	void PlayerChangeTeam(Player *player, vector<Player*> *toTeam);
	void KickPlayer(Player *player);

	static Teams* LoadTeamsByIDs(int _team1ID, int _team2ID);
	void SaveTeams(unsigned int GameID);
	void DeleteTeams();

private:
	bool FindAndRemove(Player *player);
};
