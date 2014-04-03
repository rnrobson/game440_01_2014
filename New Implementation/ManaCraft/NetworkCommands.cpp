#include "NetworkCommands.h"


using namespace ManaCraft::Client;
using namespace ManaCraft::Networking;

//bool NetworkCommands::instanceFlag = false;
//NetworkCommands* NetworkCommands::inst = NULL;
//
//NetworkCommands* NetworkCommands::getInstance(){
//	if (!instanceFlag){
//		inst = new NetworkCommands();
//		instanceFlag = true;
//		return inst;
//	}
//	else{
//		return inst;
//	}
//}

void NetworkCommands::LogIn(std::string username){

	CS_Protocol protocol = LOGIN_PLAYER;

	//char *usernameChars;
//	int usernameLength = username.length();

	//usernameChars = new char[usernameLength];

	//for (int i = 0; i < usernameLength; i++)
//	{
		//usernameChars[i] = username[i];
	//}

	//Byte* data = usernameChars;

	//Packet* tempPacket = new Packet(SEC_HEAD, protocol, data);

	//ServerLiason::getInstance()->sendtoserver(*tempPacket);
	}


