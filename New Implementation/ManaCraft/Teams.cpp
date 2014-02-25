#include "Teams.h"

Teams::Teams(int teamSize)
{
	PlayerCount = 0;
	MaxPlayers = 2 * teamSize;
}

Teams::Teams()
{
	PlayerCount = 0;
	MaxPlayers = 0;
}

Teams::~Teams(void)
{
}

void Teams::EnterNewPlayer(int player)
{
	//If game is not full:
	//++ player count.
	//Add player to bench.
	if (PlayerCount < MaxPlayers)
	{
		PlayerCount++;
		Bench.push_back(player);
	}
}

void Teams::PlayerChangeTeam(int player, vector<int> *toTeam)
{
	//If target team is not full:
	//If player exists in a team:
	//Remove player from team.
	//Add to target team.

	int teamCap;
	if (toTeam == &Bench)
	{
		teamCap = MaxPlayers;
	}
	else
	{
		teamCap = MaxPlayers / 2;
	}

	if (toTeam->size() < teamCap)
	{
		if (FindAndRemove(player))
		{
			toTeam->push_back(player);
		}
	}
}

void Teams::KickPlayer(int player)
{
	//If player exists in a team:
	//Remove player from team.
	//-- player count.
	if (FindAndRemove(player))
	{
		PlayerCount--;
	}
}

bool Teams::FindAndRemove(int player)
{
	for (int i = 0; i < Team1.size(); i++)
	{
		if (Team1.at(i) == player)
		{
			Team1.erase(Team1.begin() + i);
			return true;
		}
	}

	for (int i = 0; i < Team2.size(); i++)
	{
		if (Team2.at(i) == player)
		{
			Team2.erase(Team2.begin() + i);
			return true;
		}
	}

	for (int i = 0; i < Bench.size(); i++)
	{
		if (Bench.at(i) == player)
		{
			Bench.erase(Bench.begin() + i);
			return true;
		}
	}

	return false;
}