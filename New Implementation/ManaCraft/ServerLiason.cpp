#include "ServerLiason.h"

using namespace ManaCraft::Networking;
using namespace ManaCraft::Client;
using namespace std;

// The Connection Variable
Connection clientConnection("76.70.80.145", 25508);
SDL_Thread *listening, *sending; // The Threads
bool isRunning = false;

void ServerLiason::Start() {
	// TODO: Test with server sending data

	// Open the connection
	int openState = clientConnection.Open();

	if (openState == 0) {
		cout << "The connection didn't open, throw something." << endl;
	}
	else {
		cout << "Successfully connected on: " << clientConnection.GetIP().host << endl;
		isRunning = true;

		listening = SDL_CreateThread(ListenToServer, "listening", NULL);
		if (listening == NULL) {
			cout << "Listening didn't create its thread, throw something." << endl;
		}

		sending = SDL_CreateThread(SendToServer, "sending", NULL);
		if (sending == NULL) {
			cout << "Sending didn't create its thread, throw something." << endl;
		}
	}
}

int ServerLiason::SendToServer(void*) {
	return 0;
}

int ServerLiason::ListenToServer(void*) {
	bool listen = true;

	while (listen) {
		Byte* data; 
		int len = clientConnection.ReceiveData(&data);

		if (len > 0) { 
			cout << "Successfully received data, length is: " << len << endl;
			ProcessData(data, len);
		}
	}
	CloseConnection();
	return 0;
}

void ServerLiason::CloseConnection() {
	isRunning = false;
	clientConnection.Close();
}

void ServerLiason::ProcessData(Byte* data, int len) {
	Byte* protocolData = new char[sizeof(__int16)];
	for (int i = 0; i < sizeof(__int16); ++i)
		protocolData[i] = data[i];

	SC_Protocol protocol = (SC_Protocol)(Deserialize::Int16(protocolData));

	cout << "The deserialized protocol is: " << protocol;

	switch (protocol) {
		case ManaCraft::Networking::CLIENT_LOST:
			break;
		case ManaCraft::Networking::CLIENT_REJOIN:
			break;
		case ManaCraft::Networking::RETURN_LOGIN_STATUS:
			break;
		case ManaCraft::Networking::BROADCAST_MESSAGE_IG:
			break;
		case ManaCraft::Networking::BROADCAST_MESSAGE_GL:
			break;
		case ManaCraft::Networking::DISPLAY_WHISPER:
			break;
		case ManaCraft::Networking::BROADCAST_PARTY_MESSAGE_IG:
			break;
		case ManaCraft::Networking::BROADCAST_PARTY_MESSAGE_GL:
			break;
		case ManaCraft::Networking::POPULATE_GAMES:
			break;
		case ManaCraft::Networking::RETURN_JOIN_GAME_STATUS:
			break;
		case ManaCraft::Networking::RETURN_CREATED_GAME:
			break;
		case ManaCraft::Networking::REFRESH_LOBBY:
			break;
		case ManaCraft::Networking::RETURN_DISBAND_GAME:
			break;
		case ManaCraft::Networking::BROADCAST_DISBAND_GAME:
			break;
		case ManaCraft::Networking::RETURN_JOIN_TEAM:
			break;
		case ManaCraft::Networking::RETURN_BENCH_PLAYER:
			break;
		case ManaCraft::Networking::UPDATE_GAMEPLAY_OPTIONS:
			break;
		case ManaCraft::Networking::MINION_SUMMONED:
			break;
		case ManaCraft::Networking::BROADCAST_SUMMON_MINION:
			break;
		case ManaCraft::Networking::TOWER_PLACED:
			break;
		case ManaCraft::Networking::BROADCAST_TOWER_PLACED:
			break;
		case ManaCraft::Networking::UPDATE_ECONOMY:
			break;
		case ManaCraft::Networking::UPDATE_BASE_HP:
			break;
		case ManaCraft::Networking::ASSIGN_RESOURCE_NODE:
			break;
		case ManaCraft::Networking::RETURN_RESEARCH_MINION:
			break;
		case ManaCraft::Networking::RETURN_RESEARCH_TOWER:
			break;
		case ManaCraft::Networking::RETURN_KICK_STATUS:
			break;
		case ManaCraft::Networking::RETURN_PAUSE_GAME:
			break;
		case ManaCraft::Networking::RETURN_END_GAME:
			break;
		case ManaCraft::Networking::RETURN_RESUME_GAME:
			break;
		case ManaCraft::Networking::RETURN_QUIT_GAME:
			break;
		default:
			break;
	}
}