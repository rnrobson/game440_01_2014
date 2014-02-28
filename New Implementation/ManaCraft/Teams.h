#pragma once

#include <vector>

using namespace std;

class Teams
{
public:
	int PlayerCount;
	int MaxPlayers;
	vector<int> Bench;
	vector<int> Team1;
	vector<int> Team2;

	Teams(int teamSize);
	Teams();
	~Teams(void);

	void EnterNewPlayer(int player);
	void PlayerChangeTeam(int player, vector<int> *toTeam);
	void KickPlayer(int player);
private:
	bool FindAndRemove(int player);
};
