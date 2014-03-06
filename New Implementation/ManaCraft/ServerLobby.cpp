#include "ServerLobby.h"

ServerLobby::ServerLobby(ServerPlayer *lobbyHost, int teamSize) : teams(teamSize)
{
	host = lobbyHost;
	EnterNewPlayer(host);
}

ServerLobby::ServerLobby()
{
}


ServerLobby::~ServerLobby()
{
}

void ServerLobby::StartGame()
{
	//Start game with gameModel.teams = teams.
}

void ServerLobby::CloseLobby()
{
	//?
}

void ServerLobby::ReadyPlayer(ServerPlayer *player)
{
	readyPlayers.push_back(player);
}

void ServerLobby::UnReadyPlayer(ServerPlayer *player)
{
	for (int i = 0; i < readyPlayers.size(); i++)
	{
		if (readyPlayers.at(i) == player)
		{
			readyPlayers.erase(readyPlayers.begin() + i);
		}
	}
}

void ServerLobby::PlayerMessage(ServerPlayer *player, string message)
{
	//Send message from player.
}

void ServerLobby::EnterNewPlayer(ServerPlayer *player)
{
	teams.EnterNewPlayer(player);
}

void ServerLobby::PlayerChangeTeam(ServerPlayer *player, vector<ServerPlayer*> *toTeam)
{
	teams.PlayerChangeTeam(player, toTeam);
}

void ServerLobby::KickPlayer(ServerPlayer *player)
{
	teams.KickPlayer(player);
	UnReadyPlayer(player);
}