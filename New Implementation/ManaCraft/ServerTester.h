#ifndef SERVER_TESTER_H
#define SERVER_TESTER_H

#include "ServerCommandIncludes.h"
#include "ServerLobby.h"

class ServerTester
{
private:
	int numberOfTests;
	int numTestsFailed;
	int numTestsPassed;

	void printLobbyState(ServerLobby *lobby, int testNumber);
public:
	ServerTester(int numTests);
	~ServerTester();
	
	void Reset();
	void RunAllTests();

	void Test_Command_IntFloatProduct();
	void Test_Command_TripleAFloat();
	void Test_Command_CreateNewGame();
	void Test_Command_UpdateMinions();

	void Test_ServerLobby(ThreadPool *workCrew);
};

#endif