#include "PacketFactory.h"

Networking::Packet* PacketFactory::CreateFromClientPacket(const Networking::Packet* packet) {

	std::cout << "PacketFactory creating packet." << std::endl;

	__int16 protocol = packet->GetProtocolID();

	std::cout << "Protocol: " << protocol << std::endl;

	switch ((Networking::CS_Protocol)protocol) {
	default:
	case Networking::CLOSE_GAME:
		return new CloseGamePacket(packet);
	case Networking::LOGIN_PLAYER:
		return new LoginPlayerPacket(packet);
	case Networking::LOGOUT_PLAYER:
		return new LogoutPlayerPacket(packet);
	/*case Networking::SEND_MESSAGE_IG:
		return new SendMessageIGPacket(packet);
	case Networking::SEND_MESSAGE_GL:
		return new SendMessageGLPacket(packet);*/
	case Networking::SEND_WHISPER:
		return new SendWhisperPacket(packet);
	/*case Networking::SEND_PARTY_MSG_IG:
		return new SendPartyMsgIGPacket(packet);
	case Networking::SEND_PARTY_MSG_GL:
		return new SendPartyMsgGLPacket(packet);*/
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
		return new EndGamePacket(packet);
	case Networking::RESUME_GAME:
		return new ResumeGamePacket(packet);
	case Networking::QUIT_GAME:
		return new QuitGamePacket(packet);
	}
}

Networking::Packet* PacketFactory::CreateFromServerPacket(const Networking::Packet* packet) {
	switch (packet->GetProtocolID()) {
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

CommandPacket::CommandPacket(const Networking::Packet* packet) : Packet(*packet) {

}

#pragma region CS Packet Constructors

CloseGamePacket::CloseGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	__int16 len = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	std::cout << "Username Length: " << len << std::endl;

	char* name = new char[len + 1];
	for (int i = 0; i < len; ++i) {
		name[i] = data[index];
		++index;
	}
	name[len] = '\0';

	username.append(name);
}

LoginPlayerPacket::LoginPlayerPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	std::cout << "Username Length: " << usernameLength << std::endl;

	char* name = new char[usernameLength + 1];
	for(int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

LogoutPlayerPacket::LogoutPlayerPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	std::cout << "Username Length: " << usernameLength << std::endl;

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

SendMessageIGPacket::SendMessageIGPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;
	__int8 messageLength = 0;
	gameID = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	gameID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);

	char* msg = new char[messageLength + 1];
	for (int i = 0; i < messageLength; ++i) {
		msg[i] = data[index];
		++index;
	}
	msg[messageLength] = '\0';

	message.append(msg);
}

SendMessageGLPacket::SendMessageGLPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;
	__int8 messageLength = 0;
	lobbyID = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	lobbyID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);

	char* msg = new char[messageLength + 1];
	for (int i = 0; i < messageLength; ++i) {
		msg[i] = data[index];
		++index;
	}
	msg[messageLength] = '\0';

	message.append(msg);
}

SendWhisperPacket::SendWhisperPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 sendingUserLength = 0;
	__int8 receivingUserLength = 0;
	__int8 messageLength = 0;
	gameID = 0;
	teamID = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	/* i don't see this in the protocol
	gameID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	*/
	
	sendingUserLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	receivingUserLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* sendingName = new char[sendingUserLength + 1];
	for (int i = 0; i < sendingUserLength; ++i) {
		sendingName[i] = data[index];
		++index;
	}
	sendingName[sendingUserLength] = '\0';

	sendingUser.append(sendingName);

	char* receivingName = new char[receivingUserLength + 1];
	for (int i = 0; i < receivingUserLength; ++i) {
		receivingName[i] = data[index];
		++index;
	}
	receivingName[sendingUserLength] = '\0';

	receivingUser.append(sendingName);

	char* msg = new char[messageLength + 1];
	for (int i = 0; i < messageLength; ++i) {
		msg[i] = data[index];
		++index;
	}
	msg[messageLength] = '\0';

	message.append(msg);
}

SendPartyMsgIGPacket::SendPartyMsgIGPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;
	__int8 messageLength = 0;
	gameID = 0;
	teamID = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	gameID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);

	teamID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);

	char* msg = new char[messageLength + 1];
	for (int i = 0; i < messageLength; ++i) {
		msg[i] = data[index];
		++index;
	}
	msg[messageLength] = '\0';

	message.append(msg);
}

SendPartyMsgGLPacket::SendPartyMsgGLPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength = 0;
	__int8 messageLength = 0;
	lobbyID = 0;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	lobbyID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; ++i) {
		name[i] = data[index];
		++index;
	}
	name[usernameLength] = '\0';

	username.append(name);

	char* msg = new char[messageLength + 1];
	for (int i = 0; i < messageLength; ++i) {
		msg[i] = data[index];
		++index;
	}
	msg[messageLength] = '\0';

	message.append(msg);
}

RefreshGamesPacket::RefreshGamesPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

JoinGamePacket::JoinGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	GameID = Networking::Deserialize::Int16(data, 0);
}

CreateGamePacket::CreateGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

JoinTeamPacket::JoinTeamPacket(const Networking::Packet* packet) : CommandPacket(packet) {

	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData;

	lobbyID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	teamID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength;i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

LeaveGamePacket::LeaveGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	lobbyID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];

	for (int i = 0; i < usernameLength; i++){
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

BenchPlayerPacket::BenchPlayerPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	lobbyID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];

	for (int i = 0; i < usernameLength; i++){
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

ReadyStatusPacket::ReadyStatusPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	status = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];

	for (int i = 0; i < usernameLength; i++){
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

DisbandGamePacket::DisbandGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	gameID = Networking::Deserialize::Int16(data, 0);
}

SetGameplayOptionsPacket::SetGameplayOptionsPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

PlaceTowerPacket::PlaceTowerPacket(const Networking::Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	gameID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	towerID = Networking::Deserialize::Int16(data, index);
	index += sizeof(__int16);
	gridspace = Networking::Deserialize::Int32(data, index);
	index += sizeof(__int32);
	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];

	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

SummonMinionPacket::SummonMinionPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

ResearchMinionPacket::ResearchMinionPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

ResearchTowerPacket::ResearchTowerPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

KickPlayerPacket::KickPlayerPacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

PauseGamePacket::PauseGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

EndGamePacket::EndGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

ResumeGamePacket::ResumeGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

QuitGamePacket::QuitGamePacket(const Networking::Packet* packet) : CommandPacket(packet) {

}

#pragma endregion

#pragma region SC Packet Constructors

ClientLostPacket::ClientLostPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

ClientRejoinPacket::ClientRejoinPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

ReturnLoginStatusPacket::ReturnLoginStatusPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);

	successStatus = Networking::Deserialize::Int8(data, index);

}

BroadcastMessageInGamePacket::BroadcastMessageInGamePacket(const Packet* packet) : CommandPacket(packet) {

	__int8 usernameLength;
	__int8 messageLength;
	
	//get username length and fill the username
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	//get message length and fill the message
	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* messagetemp = new char[messageLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		messagetemp[i] = data[index];
		index++;
	}
	messagetemp[messageLength] = '\0';
	message.append(name);
}

BroadcastMessageGameLobbyPacket::BroadcastMessageGameLobbyPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;
	__int8 messageLength;

	//get username length and fill the username
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	//get message length and fill the message
	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* messagetemp = new char[messageLength + 1];
	for (int i = 0; i < messageLength; i++)
	{
		messagetemp[i] = data[index];
		index++;
	}
	messagetemp[messageLength] = '\0';
	message.append(name);
}

DisplayWhisperPacket::DisplayWhisperPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;
	__int8 recipentUsernameLength;

	//get username length and fill the username
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	//get reciever length and fill the recipents username
	recipentUsernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* recipent = new char[recipentUsernameLength + 1];
	for (int i = 0; i < recipentUsernameLength; i++)
	{
		recipent[i] = data[index];
		index++;
	}
	recipent[recipentUsernameLength] = '\0';
	receiver.append(name);
}

BroadcastPartyMessageInGamePacket::BroadcastPartyMessageInGamePacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;
	__int8 messageLength;

	//get username length and fill the username
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	//get message length and fill the message
	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* messagetemp = new char[messageLength + 1];
	for (int i = 0; i < messageLength; i++)
	{
		messagetemp[i] = data[index];
		index++;
	}
	messagetemp[messageLength] = '\0';
	message.append(name);
}

BroadcastPartyMessageGameLobbyPacket::BroadcastPartyMessageGameLobbyPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;
	__int8 messageLength;

	//get username length and fill the username
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	//get message length and fill the message
	messageLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* messagetemp = new char[messageLength + 1];
	for (int i = 0; i < messageLength; i++)
	{
		messagetemp[i] = data[index];
		index++;
	}
	messagetemp[messageLength] = '\0';
	message.append(name);
}


PopulateGamesPacket::PopulateGamesPacket(const Packet* packet) : CommandPacket(packet) {

}

ReturnJoinGameStatusPacket::ReturnJoinGameStatusPacket(const Packet* packet) : CommandPacket(packet) {
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	joinedGame = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	gameID = Networking::Deserialize::Int32(data, index);
}

ReturnCreatedGamePacket::ReturnCreatedGamePacket(const Packet* packet) : CommandPacket(packet) {
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	createdGame = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	gameID = Networking::Deserialize::Int32(data, index);
}

RefreshLobbyPacket::RefreshLobbyPacket(const Packet* packet) : CommandPacket(packet) {

}

ReturnDisbandGamePacket::ReturnDisbandGamePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	disbanded = Networking::Deserialize::Int8(data, 0);
}

BroadcastDisbandGamePacket::BroadcastDisbandGamePacket(const Packet* packet) : CommandPacket(packet) {

}

ReturnJoinTeamPacket::ReturnJoinTeamPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	joined = Networking::Deserialize::Int8(data, 0);
}

ReturnBenchPlayerPacket::ReturnBenchPlayerPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	benched = Networking::Deserialize::Int8(data, 0);
}

UpdateGameplayOptionsPacket::UpdateGameplayOptionsPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';

	username.append(name);
}

MinionSummonedPacket::MinionSummonedPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	minionSummoned = Networking::Deserialize::Int8(data, 0);
}

BroadcastSummonMinionPacket::BroadcastSummonMinionPacket(const Packet* packet) : CommandPacket(packet) {
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	minionType = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	posX = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	posY = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	teamID = Networking::Deserialize::Int8(data, 0);
}

TowerPlacedPacket::TowerPlacedPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	towerPlaced = Networking::Deserialize::Int8(data, 0);
}

BroadcastTowerPlacedPacket::BroadcastTowerPlacedPacket(const Packet* packet) : CommandPacket(packet) {
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	towerType = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	posX = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	posY = Networking::Deserialize::Int8(data, 0);
	index += sizeof(__int8);
	teamID = Networking::Deserialize::Int8(data, 0);
}

UpdateEconomyPacket::UpdateEconomyPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);

	economyValue = Networking::Deserialize::Int8(data, index);

}

UpdateBaseHealthPacket::UpdateBaseHealthPacket(const Packet* packet) : CommandPacket(packet) {
	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	teamID = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);
	hpValue = Networking::Deserialize::Int8(data, index);
}

AssignResourceNodePacket::AssignResourceNodePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	resourceAssigned = Networking::Deserialize::Int8(data, 0);
}

ReturnResearchMinionPacket::ReturnResearchMinionPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	minionResearched = Networking::Deserialize::Int8(data, 0);
}

ReturnResearchTowerPacket::ReturnResearchTowerPacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	towerResearched = Networking::Deserialize::Int8(data, 0);
}

ReturnKickStatusPacket::ReturnKickStatusPacket(const Packet* packet) : CommandPacket(packet) {
	__int8 usernameLength;

	unsigned int index = 0;
	std::vector<char> data = packet->GetData();

	usernameLength = Networking::Deserialize::Int8(data, index);
	index += sizeof(__int8);

	char* name = new char[usernameLength + 1];
	for (int i = 0; i < usernameLength; i++)
	{
		name[i] = data[index];
		index++;
	}
	name[usernameLength] = '\0';
	username.append(name);
}

ReturnPauseGamePacket::ReturnPauseGamePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	paused = Networking::Deserialize::Int8(data, 0);
}

ReturnEndGamePacket::ReturnEndGamePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	ended = Networking::Deserialize::Int8(data, 0);
}

ReturnResumeGamePacket::ReturnResumeGamePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	resumed = Networking::Deserialize::Int8(data, 0);
}

ReturnQuitGamePacket::ReturnQuitGamePacket(const Packet* packet) : CommandPacket(packet) {
	std::vector<char> data = packet->GetData();
	quit = Networking::Deserialize::Int8(data, 0);
}


#pragma endregion

#pragma region CS Packet Executes
void CloseGamePacket::Execute() {

}

void LoginPlayerPacket::Execute() {
	std::cout << "Logged in: " << username << std::endl;
}

void LogoutPlayerPacket::Execute() {

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