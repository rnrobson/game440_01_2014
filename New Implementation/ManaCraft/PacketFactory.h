#ifndef PACKET_FACTORY_H
#define PACKET_FACTORY_H

#include "Packet.h"
#include "Protocol.h"
#include "Serialize.h"
#include <iostream>
#include <string>

using namespace ManaCraft;

class PacketFactory
{ 
public:
	/// <summary>[CreateServerClientPacket]
	/// <para>Converts a regular packet into the Command Packet that corresponds to its Protocol.</para>
	/// <para> [const Packet* packet] A packet holding a protocol and the corresponding data for that command.</para>
	/// <returns>Returns the converted packet.</returns>
	/// </summary>
	static Networking::Packet* CreateFromClientPacket(const Networking::Packet* packet);

	/// <summary>[CreateClientServerPacket]
	/// <para>Converts a regular packet into the Command Packet that corresponds to its Protocol.</para>
	/// <para>[const Packet* packet] A packet holding a protocol and the corresponding data for that command.</para>
	/// <returns>Returns the converted packet.</returns>
	/// </summary>
	static Networking::Packet* CreateFromServerPacket(const Networking::Packet* packet);

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

class SendMessageIGPacket : public CommandPacket {
private:
	__int16 gameID;
	std::string username;
	std::string message;
public:
	SendMessageIGPacket(const Packet* packet);
	void Execute();
};

class SendMessageGLPacket : public CommandPacket {
	__int16 lobbyID;
	std::string username;
	std::string message;
public:
	SendMessageGLPacket(const Packet* packet);
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

class SendPartyMsgIGPacket : public CommandPacket {
private:
	std::string username;
	std::string message;
	__int16 gameID;
	__int16 teamID;
public:
	SendPartyMsgIGPacket(const Packet* packet);
	void Execute();
};

class SendPartyMsgGLPacket : public CommandPacket {
private:
	std::string username;
	std::string message;
	__int16 lobbyID;
public:
	SendPartyMsgGLPacket(const Packet* packet);
	void Execute();
};

class RefreshGamesPacket : public CommandPacket {
public:
	RefreshGamesPacket(const Packet* packet);
	void Execute();
};

class JoinGamePacket : public CommandPacket {
public:
	JoinGamePacket(const Packet* packet);
	void Execute();
};

class CreateGamePacket : public CommandPacket {
public:
	CreateGamePacket(const Packet* packet);
	void Execute();
};

class JoinTeamPacket : public CommandPacket {
public:
	JoinTeamPacket(const Packet* packet);
	void Execute();
};

class LeaveGamePacket : public CommandPacket {
public:
	LeaveGamePacket(const Packet* packet);
	void Execute();
};

class BenchPlayerPacket : public CommandPacket {
public:
	BenchPlayerPacket(const Packet* packet);
	void Execute();
};

class ReadyStatusPacket : public CommandPacket {
public:
	ReadyStatusPacket(const Packet* packet);
	void Execute();
};

class DisbandGamePacket : public CommandPacket {
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
public:
	PlaceTowerPacket(const Packet* packet);
	void Execute();
};

class SummonMinionPacket : public CommandPacket {
public:
	SummonMinionPacket(const Packet* packet);
	void Execute();
};

class ResearchMinionPacket : public CommandPacket {
public:
	ResearchMinionPacket(const Packet* packet);
	void Execute();
};

class ResearchTowerPacket : public CommandPacket {
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
public:
	PauseGamePacket(const Packet* packet);
	void Execute();
};

class EndGamePacket : public CommandPacket {
public:
	EndGamePacket(const Packet* packet);
	void Execute();
};

class ResumeGamePacket : public CommandPacket {
public:
	ResumeGamePacket(const Packet* packet);
	void Execute();
};

class QuitGamePacket : public CommandPacket {
public:
	QuitGamePacket(const Packet* packet);
	void Execute();
};
#pragma endregion

#pragma region SC_Protocol Packets

class ClientLostPacket : public CommandPacket {
public:
	ClientLostPacket(const Packet* packet);
	void Execute();
};

class ClientRejoinPacket : public CommandPacket {
public:
	ClientRejoinPacket(const Packet* packet);
	void Execute();
};

class ReturnLoginStatusPacket : public CommandPacket {
public:
	ReturnLoginStatusPacket(const Packet* packet);
	void Execute();
};

class BroadcastMessageInGamePacket : public CommandPacket {
public:
	BroadcastMessageInGamePacket(const Packet* packet);
	void Execute();
};

class BroadcastMessageGameLobbyPacket : public CommandPacket {
public:
	BroadcastMessageGameLobbyPacket(const Packet* packet);
	void Execute();
};

class DisplayWhisperPacket : public CommandPacket {
public:
	DisplayWhisperPacket(const Packet* packet);
	void Execute();
};

class BroadcastPartyMessageInGamePacket : public CommandPacket {
public:
	BroadcastPartyMessageInGamePacket(const Packet* packet);
	void Execute();
};

class BroadcastPartyMessageGameLobbyPacket : public CommandPacket {
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
public:
	ReturnJoinGameStatusPacket(const Packet* packet);
	void Execute();
};

class ReturnCreatedGamePacket : public CommandPacket {
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
public:
	ReturnJoinTeamPacket(const Packet* packet);
	void Execute();
};

class ReturnBenchPlayerPacket : public CommandPacket {
public:
	ReturnBenchPlayerPacket(const Packet* packet);
	void Execute();
};

class UpdateGameplayOptionsPacket : public CommandPacket {
public:
	UpdateGameplayOptionsPacket(const Packet* packet);
	void Execute();
};

class MinionSummonedPacket : public CommandPacket {
public:
	MinionSummonedPacket(const Packet* packet);
	void Execute();
};

class BroadcastSummonMinionPacket : public CommandPacket {
public:
	BroadcastSummonMinionPacket(const Packet* packet);
	void Execute();
};

class TowerPlacedPacket : public CommandPacket {
public:
	TowerPlacedPacket(const Packet* packet);
	void Execute();
};

class BroadcastTowerPlacedPacket : public CommandPacket {
public:
	BroadcastTowerPlacedPacket(const Packet* packet);
	void Execute();
};

class UpdateEconomyPacket : public CommandPacket {
public:
	UpdateEconomyPacket(const Packet* packet);
	void Execute();
};

class UpdateBaseHealthPacket : public CommandPacket {
public:
	UpdateBaseHealthPacket(const Packet* packet);
	void Execute();
};

class AssignResourceNodePacket : public CommandPacket {
public:
	AssignResourceNodePacket(const Packet* packet);
	void Execute();
};

class ReturnResearchMinionPacket : public CommandPacket {
public:
	ReturnResearchMinionPacket(const Packet* packet);
	void Execute();
};

class ReturnResearchTowerPacket : public CommandPacket {
public:
	ReturnResearchTowerPacket(const Packet* packet);
	void Execute();
};

class ReturnKickStatusPacket : public CommandPacket {
public:
	ReturnKickStatusPacket(const Packet* packet);
	void Execute();
};

class ReturnPauseGamePacket : public CommandPacket {
public:
	ReturnPauseGamePacket(const Packet* packet);
	void Execute();
};

class ReturnEndGamePacket : public CommandPacket {
public:
	ReturnEndGamePacket(const Packet* packet);
	void Execute();
};

class ReturnResumeGamePacket : public CommandPacket {
public:
	ReturnResumeGamePacket(const Packet* packet);
	void Execute();
};

class ReturnQuitGamePacket : public CommandPacket {
public:
	ReturnQuitGamePacket(const Packet* packet);
	void Execute();
};

#pragma endregion

#pragma region Internal Server Commands
//I know I said I'd get these done tonight but
#pragma endregion

#endif

