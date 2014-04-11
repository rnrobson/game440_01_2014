#include "ServerLobby.h"
#include "PacketFactory.h"

ServerLobby::ServerLobby(ThreadPool *workCrew, Player *lobbyHost, int teamSize) : teams(teamSize)
{
	WorkCrew = workCrew;
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
	if (readyPlayers.size() == teams.PlayerCount && teams.Team1.size() == teams.Team2.size())
	{
		int gameID = 1;
		CommandPacket *newGameCMD = new Command_CreateNewGame(gameID);
		WorkCrew->addWork(newGameCMD);
		//newGameCMD->Execute();
		CommandPacket *initNewGameCMD = new Command_InitializeNewGame(gameID, &teams, host);
		WorkCrew->addWork(initNewGameCMD);
	}

}

void ServerLobby::CloseLobby()
{
	//?
}

void ServerLobby::ReadyPlayer(Player *player)
{
	if (player->Team != &teams.Bench)
	{
		UnReadyPlayer(player);
		readyPlayers.push_back(player);
	}
}

void ServerLobby::UnReadyPlayer(Player *player)
{
	for (int i = 0; i < readyPlayers.size(); i++)
	{
		if (readyPlayers.at(i) == player)
		{
			readyPlayers.erase(readyPlayers.begin() + i);
		}
	}
}

void ServerLobby::PlayerMessage(Player *player, string message)
{
	//Send message from player.
}

void ServerLobby::EnterNewPlayer(Player *player)
{
	teams.EnterNewPlayer(player);
}

void ServerLobby::PlayerChangeTeam(Player *player, vector<Player*> *toTeam)
{
	UnReadyPlayer(player);
	teams.PlayerChangeTeam(player, toTeam);
}

void ServerLobby::KickPlayer(Player *player)
{
	teams.KickPlayer(player);
	UnReadyPlayer(player);
}