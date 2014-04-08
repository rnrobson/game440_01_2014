#include "NetworkCommands.h"


using namespace ManaCraft::Client;
using namespace ManaCraft::Networking;

void NetworkCommands::LogIn(std::string username){

	CS_Protocol protocol = LOGIN_PLAYER;

	unsigned int index = 0;
	int payloadSize = username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < username.length(); ++i) {
		data[index + i] = username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::LogOut(){
	CS_Protocol protocol = LOGOUT_PLAYER;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::CloseGame(){
	CS_Protocol protocol = CLOSE_GAME;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	/*Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}*/

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::RefreshGames(){
	CS_Protocol protocol = REFRESH_GAMES;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::CreateGame(){
	CS_Protocol protocol = CREATE_GAME;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::JoinGame(int gameID){
	CS_Protocol protocol = JOIN_GAME;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::PickTeam(short teamID){
	CS_Protocol protocol = JOIN_TEAM;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::BenchMe(){
	CS_Protocol protocol = BENCH_PLAYER;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::DisbandGame(int GameID){
	CS_Protocol protocol = DISBAND_GAME;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);

}

void NetworkCommands::LeaveGame(int lobbyID){
	CS_Protocol protocol = LEAVE_GAME;
	unsigned int index = 0;
	int payloadSize = MainMenu::username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::username.length(); ++i) {
		data[index + i] = MainMenu::username[i];
	}

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}