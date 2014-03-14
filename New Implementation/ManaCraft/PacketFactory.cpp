#include "PacketFactory.h"

Networking::Packet* PacketFactory::CreateToClientPacket(const Networking::Packet& packet) {
	switch (packet.GetProtocolID()) {
	case Networking::CLOSE_GAME:
		return new CloseGamePacket(packet);
	case Networking::LOGIN_PLAYER:
		return new LoginPacket(packet);
	case Networking::LOGOUT_PLAYER:
		return new LogoutPacket(packet);
	case Networking::SEND_MESSAGE_IG:
		return new SendMessageIGPacket(packet);
	case Networking::SEND_MESSAGE_GL:
		return new SendMessageGLPacket(packet);
	case Networking::SEND_WHISPER:
		return new SendWhisperPacket(packet);
	case Networking::SEND_PARTY_MSG_IG:
		return new SendPartyMsgIGPacket(packet);
	case Networking::SEND_PARTY_MSG_GL:
		return new SendPartyMsgGLPacket(packet);
	case Networking::REFRESH_GAMES:
		return new RefreshGamesPacket(packet);
	case Networking::JOIN_GAME:
		return new JoinGamePacket(packet);
	case Networking::CREATE_GAME:
		return new CreateGamePacket(packet);
	case Networking::JOIN_TEAM:
		return new JoinTeamPacket(packet);
	case Networking::LEAVE_GAME:
		return new LeaveGamePacket(packet);
	case Networking::BENCH_PLAYER:
		return new BenchPlayerPacket(packet);
	case Networking::READY_STATUS:
		return new ReadyStatusPacket(packet);
	case Networking::DISBAND_GAME:
		return new DisbandGamePacket(packet);
	case Networking::SET_GAMEPLAY_OPTIONS:
		return new SetGameplayOptionsPacket(packet);
	case Networking::PLACE_TOWER:
		return new PlaceTowerPacket(packet);
	case Networking::SUMMON_MINION:
		return new SummonMinionPacket(packet);
	case Networking::RESEARCH_MINION:
		return new ResearchMinionPacket(packet);
	case Networking::RESEARCH_TOWER:
		return new ResearchTowerPacket(packet);
	case Networking::KICK_PLAYER:
		return new KickPlayerPacket(packet);
	case Networking::PAUSE_GAME:
		return new PauseGamePacket(packet);
	case Networking::END_GAME:
		return new PauseGamePacket(packet);
	case Networking::RESUME_GAME:
		return new ResumeGamePacket(packet);
	case Networking::QUIT_GAME:
		return new QuitGamePacket(packet);
	}
}

Networking::Packet* PacketFactory::CreateToServerPacket(const Networking::Packet& packet) {
	switch (packet.GetProtocolID) {
	case Networking::CLIENT_LOST:
		return new ClientLostPacket(packet);
	case Networking::CLIENT_REJOIN:
		return new ClientRejoinPacket(packet);
	case Networking::RETURN_LOGIN_STATUS:
		return new ReturnLoginStatusPacket(packet);
	case Networking::BROADCAST_MESSAGE_IG:
		return new BroadcastMessageInGamePacket(packet);
	case Networking::BROADCAST_MESSAGE_GL:
		return new BroadcastMessageGameLobbyPacket(packet);
	case Networking::DISPLAY_WHISPER:
		return new DisplayWhisperPacket(packet);
	case Networking::BROADCAST_PARTY_MESSAGE_IG:
		return new BroadcastPartyMessageInGamePacket(packet);
	case Networking::BROADCAST_PARTY_MESSAGE_GL:
		return new BroadcastPartyMessageInGamePacket(packet);
	case Networking::POPULATE_GAMES:
		return new PopulateGamesPacket(packet);
	case Networking::RETURN_JOIN_GAME_STATUS:
		return new ReturnJoinGameStatusPacket(packet);
	case Networking::RETURN_CREATED_GAME:
		return new ReturnCreatedGamePacket(packet);
	case Networking::REFRESH_LOBBY:
		return new RefreshLobbyPacket(packet);
	case Networking::RETURN_DISBAND_GAME:
		return new ReturnDisbandGamePacket(packet);
	case Networking::BROADCAST_DISBAND_GAME:
		return new BroadcastDisbandGamePacket(packet);
	case Networking::RETURN_JOIN_TEAM:
		return new ReturnJoinTeamPacket(packet);
	case Networking::RETURN_BENCH_PLAYER:
		return new ReturnBenchPlayerPacket(packet);
	case Networking::UPDATE_GAMEPLAY_OPTIONS:
		return new UpdateGameplayOptionsPacket(packet);
	case Networking::MINION_SUMMONED:
		return new MinionSummonedPacket(packet);
	case Networking::BROADCAST_SUMMON_MINION:
		return new BroadcastSummonMinionPacket(packet);
	case Networking::TOWER_PLACED:
		return new TowerPlacedPacket(packet);
	case Networking::BROADCAST_TOWER_PLACED:
		return new BroadcastTowerPlacedPacket(packet);
	case Networking::UPDATE_ECONOMY:
		return new UpdateEconomyPacket(packet);
	case Networking::UPDATE_BASE_HP:
		return new UpdateBaseHealthPacket(packet);
	case Networking::ASSIGN_RESOURCE_NODE:
		return new AssignResourceNodePacket(packet);
	case Networking::RETURN_RESEARCH_MINION:
		return new ReturnResearchMinionPacket(packet);
	case Networking::RETURN_RESEARCH_TOWER:
		return new ReturnResearchTowerPacket(packet);
	case Networking::RETURN_KICK_STATUS:
		return new ReturnKickStatusPacket(packet);
	case Networking::RETURN_PAUSE_GAME:
		return new ReturnPauseGamePacket(packet);
	case Networking::RETURN_END_GAME:
		return new ReturnEndGamePacket(packet);
	case Networking::RETURN_RESUME_GAME:
		return new ReturnResumeGamePacket(packet);
	case Networking::RETURN_QUIT_GAME:
		return new ReturnQuitGamePacket(packet);
	}
}

#pragma region CS Packet Executes
void CloseGamePacket::Execute() {

}

void LoginPacket::Execute() {

}

void LogoutPacket::Execute() {

}

void SendMessageIGPacket::Execute() {

}

void SendMessageGLPacket::Execute() {

}

void SendWhisperPacket::Execute() {

}

void SendPartyMsgIGPacket::Execute() {

}

void SendPartyMsgGLPacket::Execute() {

}

void RefreshGamesPacket::Execute() {

}

void JoinGamePacket::Execute() {

}

void CreateGamePacket::Execute() {

}

void JoinTeamPacket::Execute() {

}

void LeaveGamePacket::Execute() {

}

void BenchPlayerPacket::Execute() {

}

void ReadyStatusPacket::Execute() {

}

void DisbandGamePacket::Execute() {

}

void SetGameplayOptionsPacket::Execute() {

}

void PlaceTowerPacket::Execute() {

}

void SummonMinionPacket::Execute() {

}

void ResearchMinionPacket::Execute() {

}

void ResearchTowerPacket::Execute() {

}

void KickPlayerPacket::Execute() {

}

void PauseGamePacket::Execute() {

}

void EndGamePacket::Execute() {

}

void ResumeGamePacket::Execute() {

}

void QuitGamePacket::Execute() {

}
#pragma endregion

#pragma region SC Packet Executes

void ClientLostPacket::Execute() {

}

void ClientRejoinPacket::Execute() {

}

void ReturnLoginStatusPacket::Execute() {

}

void BroadcastMessageInGamePacket::Execute() {

}

void BroadcastMessageGameLobbyPacket::Execute() {

}

void DisplayWhisperPacket::Execute() {

}

void BroadcastPartyMessageInGamePacket::Execute() {

}

void BroadcastPartyMessageGameLobbyPacket::Execute() {

}

void PopulateGamesPacket::Execute() {

}

void ReturnJoinGameStatusPacket::Execute() {

}

void ReturnCreatedGamePacket::Execute() {

}

void RefreshLobbyPacket::Execute() {

}

void ReturnDisbandGamePacket::Execute() {

}

void BroadcastDisbandGamePacket::Execute() {

}

void ReturnJoinTeamPacket::Execute() {

}

void ReturnBenchPlayerPacket::Execute() {

}

void UpdateGameplayOptionsPacket::Execute() {

}

void MinionSummonedPacket::Execute() {

}

void BroadcastSummonMinionPacket::Execute() {

}

void TowerPlacedPacket::Execute() {

}

void BroadcastTowerPlacedPacket::Execute() {

}

void UpdateEconomyPacket::Execute() {

}

void UpdateBaseHealthPacket::Execute() {

}

void AssignResourceNodePacket::Execute() {

}

void ReturnResearchMinionPacket::Execute() {

}

void ReturnResearchTowerPacket::Execute() {

}

void ReturnKickStatusPacket::Execute() {

}

void ReturnPauseGamePacket::Execute() {

}

void ReturnEndGamePacket::Execute() {

}

void ReturnResumeGamePacket::Execute() {

}

void ReturnQuitGamePacket::Execute() {

}

#pragma endregion

#pragma region IS Packet Executes

//welp

#pragma endregion