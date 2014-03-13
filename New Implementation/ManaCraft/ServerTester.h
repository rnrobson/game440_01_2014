#ifndef SERVER_TESTER_H
#define SERVER_TESTER_H

#include "ServerCommandIncludes.h"

class ServerTester
{
private:
	int numberOfTests;
	int numTestsFailed;
	int numTestsPassed;
public:
	ServerTester(int numTests);
	~ServerTester();
	
	void Reset();
	void RunAllTests();

	void Test_Command_IntFloatProduct();
	void Test_Command_TripleAFloat();
	void Test_Command_CreateNewGame();
	void Test_Command_UpdateMinions();
};

#endif