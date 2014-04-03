#include "NetworkCommands.h"


using namespace ManaCraft::Client;
using namespace ManaCraft::Networking;

void NetworkCommands::LogIn(std::string username){

	CS_Protocol protocol = LOGIN_PLAYER;
	std::vector<char> data = std::vector<char>();
	
	unsigned int index = 0;
	__int16 length = username.length();

	Serialize::UInt16(data, index, length);

	//index += sizeof(__int16); 
	//std::cout << length;
	



	//char *usernameChars;
//	int usernameLength = username.length();

	//usernameChars = new char[usernameLength];

	//for (int i = 0; i < usernameLength; i++)
//	{
		//usernameChars[i] = username[i];
	//}

	//Byte* data = usernameChars;

	//Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);

	//ServerLiason::SendPacket(Networking::Packet* packet)
	}

void NetworkCommands::LogOut(){
	CS_Protocol protocol = LOGOUT_PLAYER;
	std::vector<char> data = std::vector<char>();


	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}

void NetworkCommands::CloseGame(){
	CS_Protocol protocol = CLOSE_GAME;
	std::vector<char> data = std::vector<char>();


	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}

void NetworkCommands::RefreshGames(){
	CS_Protocol protocol = REFRESH_GAMES;
	std::vector<char> data = std::vector<char>();
	
	
	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}

void NetworkCommands::CreateGame(){
	CS_Protocol protocol = CREATE_GAME;
	std::vector<char> data = std::vector<char>();
	
	
	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}

void NetworkCommands::JoinGame(int gameID){
	CS_Protocol protocol = JOIN_GAME;
	std::vector<char> data = std::vector<char>();
	
	
	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}

void NetworkCommands::PickTeam(short teamID){
	CS_Protocol protocol = JOIN_TEAM;
	std::vector<char> data = std::vector<char>();
	
	
	Packet tempPacket = Packet(SEC_HEAD, protocol, data);
	//ServerLiason::SendPacket(Networking::Packet* packet)
}



