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
	int payloadSize = 1; // MainMenu::GetInstance()->username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);

	//index += sizeof(__int8);

	//for (unsigned int i = 0; i < MainMenu::GetInstance()->username.length(); ++i) {
	//	data[index + i] = MainMenu::GetInstance()->username[i];
	//}
	

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::CloseGame(){
	CS_Protocol protocol = CLOSE_GAME;
	
	unsigned int index = 0;
	int payloadSize = MainMenu::GetInstance()->username.length() + sizeof(__int8);
	std::vector<char> data = std::vector<char>(payloadSize);

	Serialize::UInt16(data, index, payloadSize);

	/*index += sizeof(__int8);

	for (unsigned int i = 0; i < MainMenu::GetInstance()->username.length(); ++i) {
		data[index + i] = MainMenu::GetInstance()->username[i];
	}*/

	Packet* packet = new Packet(Networking::SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(packet);
}

void NetworkCommands::RefreshGames(){
	CS_Protocol protocol = REFRESH_GAMES;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}

void NetworkCommands::CreateGame(){
	CS_Protocol protocol = CREATE_GAME;
	std::vector<char> data = std::vector<char>(1);

	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}

void NetworkCommands::JoinGame(int gameID){
	CS_Protocol protocol = JOIN_GAME;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}

void NetworkCommands::PickTeam(short teamID){
	CS_Protocol protocol = JOIN_TEAM;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}

void NetworkCommands::BenchMe(){
	CS_Protocol protocol = BENCH_PLAYER;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}

void NetworkCommands::DisbandGame(int GameID){
	CS_Protocol protocol = DISBAND_GAME;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);

}

void NetworkCommands::LeaveGame(int lobbyID){
	CS_Protocol protocol = LEAVE_GAME;
	std::vector<char> data = std::vector<char>(1);


	Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);
	ServerLiason::SendPacket(tempPacket);
}