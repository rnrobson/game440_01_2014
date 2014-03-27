#include "ServerLobby.h"
#include "PacketFactory.h"

ServerLobby::ServerLobby(ThreadPool *workCrew, ServerPlayer *lobbyHost, int teamSize) : teams(teamSize)
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

		GameModel *gameModel;
		gameModel = GameManager::FindGame(gameID);
		gameModel->teams = &teams;
		gameModel->host = host;
	}

}

void ServerLobby::CloseLobby()
{
	//?
}

void ServerLobby::ReadyPlayer(ServerPlayer *player)
{
	if (player->Team != &teams.Bench)
	{
		UnReadyPlayer(player);
		readyPlayers.push_back(player);
	}
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
	UnReadyPlayer(player);
	teams.PlayerChangeTeam(player, toTeam);
}

void ServerLobby::KickPlayer(ServerPlayer *player)
{
	teams.KickPlayer(player);
	UnReadyPlayer(player);
}