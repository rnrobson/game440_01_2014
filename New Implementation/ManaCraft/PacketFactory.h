#ifndef PACKET_FACTORY_H
#define PACKET_FACTORY_H

#include "Packet.h"
#include "Protocol.h"
#include "Serialize.h"
#include <iostream>
#include <string>

using namespace ManaCraft;

class CommandPacket;

class PacketFactory
{ 
public:
	/// <summary>[CreateServerClientPacket]
	/// <para>Converts a regular packet into the Command Packet that corresponds to its Protocol.</para>
	/// <para> [const Packet* packet] A packet holding a protocol and the corresponding data for that command.</para>
	/// <returns>Returns the converted packet.</returns>
	/// </summary>
	static CommandPacket* CreateFromClientPacket(const Networking::Packet* packet);

	/// <summary>[CreateClientServerPacket]
	/// <para>Converts a regular packet into the Command Packet that corresponds to its Protocol.</para>
	/// <para>[const Packet* packet] A packet holding a protocol and the corresponding data for that command.</para>
	/// <returns>Returns the converted packet.</returns>
	/// </summary>
	static CommandPacket* CreateFromServerPacket(const Networking::Packet* packet);

private: 
	PacketFactory() { };
	~PacketFactory() { };
};

class CommandPacket : public Networking::Packet {
public:
	CommandPacket(const Packet* packet);
};

#pragma region CS_Protocol Packets

class CloseGamePacket : public CommandPacket {
private:
	std::string username;
public:
	CloseGamePacket(const Packet* packet);
	void Execute();
};

class LoginPlayerPacket : public CommandPacket {
private:
	std::string username;
public:
	LoginPlayerPacket(const Packet* packet);
	void Execute();
};

class LogoutPlayerPacket : public CommandPacket {
private:
	std::string username;
public:
	LogoutPlayerPacket(const Packet* packet);
	void Execute();
};

class SendLobbyMessagePacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
	std::string message;
public:
	SendLobbyMessagePacket(const Packet* packet);
	void Execute();
};

class SendWhisperPacket : public CommandPacket {
private:
	std::string sendingUser;
	std::string receivingUser;
	std::string message;
	__int16 gameID;
	__int16 teamID;
public:
	SendWhisperPacket(const Packet* packet);
	void Execute();
};

class SendPartyMessagePacket : public CommandPacket {
private:
	std::string username;
	std::string message;
	__int16 gameID;
	__int16 teamID;
public:
	SendPartyMessagePacket(const Packet* packet);
	void Execute();
};

class RefreshGamesPacket : public CommandPacket {
private:
	std::string username;
public:
	RefreshGamesPacket(const Packet* packet);
	void Execute();
};

class JoinGamePacket : public CommandPacket {
private:
	__int16 GameID;
	std::string username;
public:
	JoinGamePacket(const Packet* packet);
	void Execute();
};

class CreateGamePacket : public CommandPacket {
	__int16 GameID;
public:
	CreateGamePacket(const Packet* packet);
	void Execute();
};

class JoinTeamPacket : public CommandPacket {
private:
	__int16 lobbyID;
	__int16 teamID;
	std::string username;
public:
	JoinTeamPacket(const Packet* packet);
	void Execute();
};

class LeaveGamePacket : public CommandPacket {
private:
	__int16 lobbyID;
	std::string username;
public:
	LeaveGamePacket(const Packet* packet);
	void Execute();
};

class BenchPlayerPacket : public CommandPacket {
private:
	_int16 lobbyID;
	std::string username;
public:
	BenchPlayerPacket(const Packet* packet);
	void Execute();
};

class ReadyStatusPacket : public CommandPacket {
private:
	__int8 status;
	std::string username;
public:
	ReadyStatusPacket(const Packet* packet);
	void Execute();
};

class DisbandGamePacket : public CommandPacket {
private:
	//__int16 gameID;
	__int16 lobbyID;
public:
	DisbandGamePacket(const Packet* packet);
	void Execute();
};

class SetGameplayOptionsPacket : public CommandPacket {
public:
	SetGameplayOptionsPacket(const Packet* packet);
	void Execute();
};

class PlaceTowerPacket : public CommandPacket {
private:
	__int16 gameID;
	__int16 towerID;
	__int32 gridspace;
	std::string username;
public:
	PlaceTowerPacket(const Packet* packet);
	void Execute();
};

class SummonMinionPacket : public CommandPacket {
private:
	__int16 gameID;
	__int16 minionID;
	std::string username;
public:
	SummonMinionPacket(const Packet* packet);
	void Execute();
};

class ResearchMinionPacket : public CommandPacket {
private: 
	__int16 minionID;
	std::string username;
public:
	ResearchMinionPacket(const Packet* packet);
	void Execute();
};

class ResearchTowerPacket : public CommandPacket {
private:
	__int16 towerID;
	std::string username;
public:
	ResearchTowerPacket(const Packet* packet);
	void Execute();
};

class KickPlayerPacket : public CommandPacket {
public:
	KickPlayerPacket(const Packet* packet);
	void Execute();
};

class PauseGamePacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
public:
	PauseGamePacket(const Packet* packet);
	void Execute();
};

class EndGamePacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
public:
	EndGamePacket(const Packet* packet);
	void Execute();
};

class ResumeGamePacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
public:
	ResumeGamePacket(const Packet* packet);
	void Execute();
};

class QuitGamePacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
public:
	QuitGamePacket(const Packet* packet);
	void Execute();
};
#pragma endregion

#pragma region SC_Protocol Packets

class ClientLostPacket : public CommandPacket {
private:
	std::string username;
public:
	ClientLostPacket(const Packet* packet);
	void Execute();
};

class ClientRejoinPacket : public CommandPacket {
private:
	std::string username;
public:
	ClientRejoinPacket(const Packet* packet);
	void Execute();
};

class ReturnLoginStatusPacket : public CommandPacket {
private:
	std::string username;
	__int8 successStatus;
public:
	ReturnLoginStatusPacket(const Packet* packet);
	void Execute();
};

class BroadcastMessageInGamePacket : public CommandPacket {
private:
	std::string username;
	std::string message;
public:
	BroadcastMessageInGamePacket(const Packet* packet);
	void Execute();
};

class BroadcastMessageGameLobbyPacket : public CommandPacket {
private:
	std::string username;
	std::string message;
public:
	BroadcastMessageGameLobbyPacket(const Packet* packet);
	void Execute();
};

class DisplayWhisperPacket : public CommandPacket {
private:
	std::string username;
	std::string receiver;
public:
	DisplayWhisperPacket(const Packet* packet);
	void Execute();
};

class BroadcastPartyMessageInGamePacket : public CommandPacket {
private:
	std::string username;
	std::string message;
public:
	BroadcastPartyMessageInGamePacket(const Packet* packet);
	void Execute();
};

class BroadcastPartyMessageGameLobbyPacket : public CommandPacket {
private:
	std::string username;
	std::string message;
public:
	BroadcastPartyMessageGameLobbyPacket(const Packet* packet);
	void Execute();
};

class PopulateGamesPacket : public CommandPacket {
public:
	PopulateGamesPacket(const Packet* packet);
	void Execute();
};

class ReturnJoinGameStatusPacket : public CommandPacket {
private:
	__int8 joinedGame; // boolean
	__int32 gameID; //i don't know why this gameID is 4 bytes whereas all others are 2 (masterlist and protocol.h are inconsistent!)
public:
	ReturnJoinGameStatusPacket(const Packet* packet);
	void Execute();
};

class ReturnCreatedGamePacket : public CommandPacket {
private:
	__int8 createdGame; // boolean
	__int32 gameID; //i don't know why this gameID is 4 bytes whereas all others are 2 (masterlist and protocol.h are inconsistent!)
public:
	ReturnCreatedGamePacket(const Packet* packet);
	void Execute();
};

class RefreshLobbyPacket : public CommandPacket {
public:
	RefreshLobbyPacket(const Packet* packet);
	void Execute();
};

class ReturnDisbandGamePacket : public CommandPacket {
private:
	__int8 disbanded;
public:
	ReturnDisbandGamePacket(const Packet* packet);
	void Execute();
};

class BroadcastDisbandGamePacket : public CommandPacket {
public:
	BroadcastDisbandGamePacket(const Packet* packet);
	void Execute();
};

class ReturnJoinTeamPacket : public CommandPacket {
private:
	__int8 joined;
public:
	ReturnJoinTeamPacket(const Packet* packet);
	void Execute();
};

class ReturnBenchPlayerPacket : public CommandPacket {
private:
	__int8 benched;
public:
	ReturnBenchPlayerPacket(const Packet* packet);
	void Execute();
};

class UpdateGameplayOptionsPacket : public CommandPacket {
private:
	std::string username;
public:
	UpdateGameplayOptionsPacket(const Packet* packet);
	void Execute();
};

class MinionSummonedPacket : public CommandPacket {
private:
	__int8 minionSummoned;
public:
	MinionSummonedPacket(const Packet* packet);
	void Execute();
};

class BroadcastSummonMinionPacket : public CommandPacket {
private:
	__int8 minionType;
	__int8 posX;
	__int8 posY;
	__int8 teamID;
public:
	BroadcastSummonMinionPacket(const Packet* packet);
	void Execute();
};

class TowerPlacedPacket : public CommandPacket {
private:
	__int8 towerPlaced;
public:
	TowerPlacedPacket(const Packet* packet);
	void Execute();
};

class BroadcastTowerPlacedPacket : public CommandPacket {
private:
	__int8 towerType;
	__int8 posX;
	__int8 posY;
	__int8 teamID;
public:
	BroadcastTowerPlacedPacket(const Packet* packet);
	void Execute();
};

class UpdateEconomyPacket : public CommandPacket {
private:
	std::string username;
	__int8 economyValue;
public:
	UpdateEconomyPacket(const Packet* packet);
	void Execute();
};

class UpdateBaseHealthPacket : public CommandPacket {
private:
	__int8 teamID;
	__int8 hpValue;
public:
	UpdateBaseHealthPacket(const Packet* packet);
	void Execute();
};

class AssignResourceNodePacket : public CommandPacket {
private:
	__int8 resourceAssigned;
public:
	AssignResourceNodePacket(const Packet* packet);
	void Execute();
};

class ReturnResearchMinionPacket : public CommandPacket {
private:
	__int8 minionResearched;
public:
	ReturnResearchMinionPacket(const Packet* packet);
	void Execute();
};

class ReturnResearchTowerPacket : public CommandPacket {
private:
	__int8 towerResearched;
public:
	ReturnResearchTowerPacket(const Packet* packet);
	void Execute();
};

class ReturnKickStatusPacket : public CommandPacket {
private:
	std::string username;
public:
	ReturnKickStatusPacket(const Packet* packet);
	void Execute();
};

class ReturnPauseGamePacket : public CommandPacket {
private:
	__int8 paused;
public:
	ReturnPauseGamePacket(const Packet* packet);
	void Execute();
};

class ReturnEndGamePacket : public CommandPacket {
private:
	__int8 ended;
public:
	ReturnEndGamePacket(const Packet* packet);
	void Execute();
};

class ReturnResumeGamePacket : public CommandPacket {
private:
	__int8 resumed;
public:
	ReturnResumeGamePacket(const Packet* packet);
	void Execute();
};

class ReturnQuitGamePacket : public CommandPacket {
private:
	__int8 quit;
public:
	ReturnQuitGamePacket(const Packet* packet);
	void Execute();
};

#pragma endregion

#pragma region Internal Server Commands
//I know I said I'd get these done tonight but
#pragma endregion

#endif

