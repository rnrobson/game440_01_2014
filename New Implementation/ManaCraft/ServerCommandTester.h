#ifndef SERVER_COMMAND_TESTER_H
#define SERVER_COMMAND_TESTER_H

#include "ServerCommandIncludes.h"

class ServerCommandTester
{
private:
	int numberOfTests;
	int numTestsFailed;
	int numTestsPassed;
public:
	ServerCommandTester(int numTests);
	~ServerCommandTester();
	
	void Reset();
	void RunAllTests();

	void TestIntFloatProductCommand();
	void TestTripleAFloatCommand();
};

#endif